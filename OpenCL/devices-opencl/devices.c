#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#include <CL/cl.h>
#endif

int main(int argc, char const *argv[]) {

	printf("===Device Query===\n");

	cl_uint 			numPlatforms;
	clGetPlatformIDs(0, NULL, &numPlatforms);
	printf("Number of OpenCL platforms: %d\n", numPlatforms);

	cl_platform_id platforms[numPlatforms];
	clGetPlatformIDs(numPlatforms, platforms, NULL);

	cl_char string[1000];

	// info about each platform
	int i, j;
	cl_uint number;
	for (i = 0; i < numPlatforms; i++) {

		clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(string), &string, NULL);
		printf("%d: %s\n", (i+1), string);
		clGetPlatformInfo(platforms[i], CL_PLATFORM_VERSION, sizeof(string), &string, NULL);
		printf("\tOpenCL Version: %s\n", string);

		// find devices in each platform
		cl_uint num_devices;
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
		cl_device_id devices[num_devices];
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, num_devices, devices, NULL);
		printf("\tNumber of devices: %d\n", num_devices);

		// info about each device
		for (j = 0; j < num_devices; ++j) {
			clGetDeviceInfo(devices[j], CL_DEVICE_NAME, sizeof(string), &string, NULL);
			printf("\t%d.%d: %s\n", (i+1), (j+1), string);
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &number, NULL);
			printf("\t\tMax Compute Units: %d\n", number);
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(cl_uint), &number, NULL);
			printf("\t\tMax Work Group Size: %d\n", number);
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint), &number, NULL);
			printf("\t\tMax Work Item Dim: %d\n", number);
			size_t arr[3];
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(arr), &arr, NULL);
			printf("\t\tMax Work Item Size: %d, %d, %d\n", arr[0], arr[1], arr[2]);
		}
	}

	return EXIT_SUCCESS;
}
