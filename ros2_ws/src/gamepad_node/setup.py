from setuptools import find_packages, setup

package_name = 'gamepad_node'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'geometry_msgs', 'sensor_msgs'],
    zip_safe=True,
    maintainer='adonis',
    maintainer_email='adonis@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "gamepad = gamepad_node.gamepad:main",
        ],
    },
)
