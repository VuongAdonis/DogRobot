#include "serial.h"
#include "wit_c_sdk.h"
#include "REG.h"
#include <stdint.h>
#include <dirent.h>
#include <unistd.h>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/imu.hpp"

#define ACC_UPDATE		0x01
#define GYRO_UPDATE		0x02
#define ANGLE_UPDATE	0x04
#define MAG_UPDATE		0x08
#define READ_UPDATE		0x80


static int fd, s_iCurBaud = 9600;
static volatile char s_cDataUpdate = 0;


const int c_uiBaud[] = {2400 , 4800 , 9600 , 19200 , 38400 , 57600 , 115200 , 230400 , 460800 , 921600};


static void AutoScanSensor(char* dev);
static void SensorDataUpdata(uint32_t uiReg, uint32_t uiRegNum);
static void Delayms(uint16_t ucMs);

#define BUFFER_SIZE 256

float angle[3] = {0, 0, 0};

void responseFunction(const std::shared_ptr<custom_interfaces::srv::IMU::Request> 
request, std::shared_ptr<custom_interfaces::srv::IMU::Response> response)
{
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na");
	response->angle = std::vector<double>(angle, angle + 3);

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response");

}

void spin_node(std::shared_ptr<rclcpp::Node> node) {
    rclcpp::spin(node);
}

int main(int argc,char* argv[]){
	
	DIR *dir;
    struct dirent *ent;
    char serial_port[BUFFER_SIZE];
    int found = 0;
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response");
	rclcpp::init(argc, argv);
	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("imu_server");
	rclcpp::Service<custom_interfaces::srv::IMU>::SharedPtr service =
	node->create_service<custom_interfaces::srv::IMU>("imu", &responseFunction);
	// Khởi động spin trong một thread riêng
    std::thread spin_thread(spin_node, node);

	
	// Mở thư mục /dev
	if ((dir = opendir("/dev")) != NULL) {
		// Quét qua các file trong thư mục
		while ((ent = readdir(dir)) != NULL) {
			// Kiểm tra nếu file là cổng serial
			if (strncmp(ent->d_name, "ttyUSB", 6) == 0) {
				snprintf(serial_port, sizeof(serial_port), "/dev/%s", ent->d_name);
				printf("Found serial port: %s\n", serial_port);
				found = 1;
				break;
			}
		}
	}

	// argv[1] = "/dev/ttyUSB1";


	if((fd = serial_open((unsigned char*)serial_port , 115200)<0))
	{
		printf("open %s fail\n", serial_port);
		return 0;
	}
	else printf("open %s success\n", serial_port);


	float fAcc[3], fGyro[3], fAngle[3];
	int i , ret;
	char cBuff[1];
	
	WitInit(WIT_PROTOCOL_NORMAL, 0x50);
	WitRegisterCallBack(SensorDataUpdata);
	
	printf("\r\n********************** wit-motion Normal example  ************************\r\n");
	AutoScanSensor(serial_port);
	
	while(1 && rclcpp::ok())
	{
		
		while(serial_read_data(fd, (unsigned char*)cBuff, 1))
		{
			WitSerialDataIn(cBuff[0]);
		}
		printf("\n");
		Delayms(500);
		
		if(s_cDataUpdate)
		{
			for(i = 0; i < 3; i++)
				{
					fAcc[i] = sReg[AX+i] / 32768.0f * 16.0f;
					fGyro[i] = sReg[GX+i] / 32768.0f * 2000.0f;
					fAngle[i] = sReg[Roll+i] / 32768.0f * 180.0f;
				}

			if(s_cDataUpdate & ACC_UPDATE)
				{
				printf("acc:%.3f %.3f %.3f\r\n", fAcc[0], fAcc[1], fAcc[2]);
				s_cDataUpdate &= ~ACC_UPDATE;
				}
			if(s_cDataUpdate & GYRO_UPDATE)
				{
				printf("gyro:%.3f %.3f %.3f\r\n", fGyro[0], fGyro[1], fGyro[2]);
				s_cDataUpdate &= ~GYRO_UPDATE;
				}
			if(s_cDataUpdate & ANGLE_UPDATE)
				{
				printf("angle:%.3f %.3f %.3f\r\n", fAngle[0], fAngle[1], fAngle[2]);
				angle[0] = fAngle[0];
				angle[1] = fAngle[1];
				angle[2] = fAngle[2];
				s_cDataUpdate &= ~ANGLE_UPDATE;
				}
			if(s_cDataUpdate & MAG_UPDATE)
				{
				printf("mag:%d %d %d\r\n", sReg[HX], sReg[HY], sReg[HZ]);
				s_cDataUpdate &= ~MAG_UPDATE;
				}
			}
	}
    
    serial_close(fd);
	rclcpp::shutdown();
	return 0;
}


static void SensorDataUpdata(uint32_t uiReg, uint32_t uiRegNum)
{
    int i;
    for(i = 0; i < uiRegNum; i++)
    {
        switch(uiReg)
        {
//            case AX:
//            case AY:
            case AZ:
				s_cDataUpdate |= ACC_UPDATE;
            break;
//            case GX:
//            case GY:
            case GZ:
				s_cDataUpdate |= GYRO_UPDATE;
            break;
//            case HX:
//            case HY:
            case HZ:
				s_cDataUpdate |= MAG_UPDATE;
            break;
//            case Roll:
//            case Pitch:
            case Yaw:
				s_cDataUpdate |= ANGLE_UPDATE;
            break;
            default:
				s_cDataUpdate |= READ_UPDATE;
			break;
        }
		uiReg++;
    }
}


static void Delayms(uint16_t ucMs)
{ 
     usleep(ucMs*1000);
}
 
	
static void AutoScanSensor(char* dev)
{
	int i, iRetry;
	char cBuff[1];
	
	for(i = 1; i < 10; i++)
	{
		serial_close(fd);
		s_iCurBaud = c_uiBaud[i];
		fd = serial_open((unsigned char*)dev , c_uiBaud[i]);
		
		iRetry = 2;
		do
		{
			s_cDataUpdate = 0;
			WitReadReg(AX, 3);
			Delayms(200);
			while(serial_read_data(fd, (unsigned char*)cBuff, 1))
			{
				WitSerialDataIn(cBuff[0]);
			}
			if(s_cDataUpdate != 0)
			{
				printf("%d baud find sensor\r\n\r\n", c_uiBaud[i]);
				return ;
			}
			iRetry--;
		}while(iRetry);		
	}
	printf("can not find sensor\r\n");
	printf("please check your connection\r\n");
}
