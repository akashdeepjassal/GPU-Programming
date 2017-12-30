
Learn OpenCL step by step as below.

1. OpenCL Examples
2. Installation Guide of OpenCL

# 1. OpenCL Examples

1. [vec-add-standard](./vec-add-standard): An standard OpenCL example, accomplish addition operation of two int-type arrays (vectors).
2. [vec-add-simple](./vec-add-simple): An simple addition operation of two vectors (NOT recommanded).
3. [bandwidth](./bandwidth): Measure bandwith for various variable type.
4. [mat-transpose](./mat-transpose): An demo of matrix transpose with two OpenCL kernels.
5. [devices-opencl](./devices-opencl): Get list of OpenCL Devices.


# 2. Installation Guide of OpenCL

You can choose one or two ways to use OpenCL:  
1. Install OpenCL on Ubuntu 16.04 64-bit  

## 2.1 Install OpenCL on Ubuntu 16.04 64-bit

```Shell

$ sudo apt-get update
$ sudo apt-get install build-essential g++ cmake
$ sudo apt-get install clang libclang-3.4-dev libclang-dev libclang1
$ sudo apt-get install ocl-icd-opencl-dev ocl-icd-libopencl1
$ sudo apt-get install opencl-headers ocl-icd-dev ocl-icd-libopencl1
$ sudo apt-get install mesa-*


$ sudo apt install ocl-icd-libopencl1
$ sudo apt install opencl-headers
$ sudo apt install clinfo
$ sudo apt install ocl-icd-opencl-dev
$ sudo apt install beignet
```


## 2.3 Verify Installation

Using instruction below, successful installation will print same following messages:
```shell
$ clinfo

# print message below

Number of platforms                               1
  Platform Name                                   Clover
  Platform Vendor                                 Mesa
  Platform Version                                OpenCL 1.1 Mesa 17.4.0-devel
  Platform Profile                                FULL_PROFILE
  Platform Extensions                             cl_khr_icd
  Platform Extensions function suffix             MESA

  Platform Name                                   Clover
Number of devices                                 1
  Device Name                                     AMD CAPE VERDE (DRM 2.49.0 / 4.10.0-42-generic, LLVM 5.0.1)
  Device Vendor                                   AMD
  Device Vendor ID                                0x1002
  Device Version                                  OpenCL 1.1 Mesa 17.4.0-devel
  Driver Version                                  17.4.0-devel
  Device OpenCL C Version                         OpenCL C 1.1
  Device Type                                     GPU
  Device Profile                                  FULL_PROFILE
  Max compute units                               10
  Max clock frequency                             1015MHz
  Max work item dimensions                        3
  Max work item sizes                             256x256x256
  Max work group size                             256
  Preferred work group size multiple              64
  Preferred / native vector sizes                 
    char                                                16 / 16      
    short                                                8 / 8       
    int                                                  4 / 4       
    long                                                 2 / 2       
    half                                                 8 / 8        (cl_khr_fp16)
    float                                                4 / 4       
    double                                               2 / 2        (cl_khr_fp64)
  Half-precision Floating-point support           (cl_khr_fp16)
    Denormals                                     No
    Infinity and NANs                             Yes
    Round to nearest                              Yes
    Round to zero                                 No
    Round to infinity                             No
    IEEE754-2008 fused multiply-add               No
    Support is emulated in software               No
    Correctly-rounded divide and sqrt operations  No
  Single-precision Floating-point support         (core)
    Denormals                                     No
    Infinity and NANs                             Yes
    Round to nearest                              Yes
    Round to zero                                 No
    Round to infinity                             No
    IEEE754-2008 fused multiply-add               No
    Support is emulated in software               No
    Correctly-rounded divide and sqrt operations  No
  Double-precision Floating-point support         (cl_khr_fp64)
    Denormals                                     Yes
    Infinity and NANs                             Yes
    Round to nearest                              Yes
    Round to zero                                 Yes
    Round to infinity                             Yes
    IEEE754-2008 fused multiply-add               Yes
    Support is emulated in software               No
    Correctly-rounded divide and sqrt operations  No
  Address bits                                    64, Little-Endian
  Global memory size                              4294967296 (4GiB)
  Error Correction support                        No
  Max memory allocation                           3006477107 (2.8GiB)
  Unified memory for Host and Device              No
  Minimum alignment for any data type             128 bytes
  Alignment of base address                       32768 bits (4096 bytes)
  Global Memory cache type                        None
  Image support                                   No
  Local memory type                               Local
  Local memory size                               32768 (32KiB)
  Max constant buffer size                        2147483647 (2GiB)
  Max number of constant args                     16
  Max size of kernel argument                     1024
  Queue properties                                
    Out-of-order execution                        No
    Profiling                                     Yes
  Profiling timer resolution                      0ns
  Execution capabilities                          
    Run OpenCL kernels                            Yes
    Run native kernels                            No
  Device Available                                Yes
  Compiler Available                              Yes
  Device Extensions                               cl_khr_byte_addressable_store cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_fp64 cl_khr_fp16

NULL platform behavior
  clGetPlatformInfo(NULL, CL_PLATFORM_NAME, ...)  Clover
  clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, ...)   Success [MESA]
  clCreateContext(NULL, ...) [default]            Success [MESA]
  clCreateContextFromType(NULL, CL_DEVICE_TYPE_CPU)  No devices found in platform
  clCreateContextFromType(NULL, CL_DEVICE_TYPE_GPU)  Success (1)
    Platform Name                                 Clover
    Device Name                                   AMD CAPE VERDE (DRM 2.49.0 / 4.10.0-42-generic, LLVM 5.0.1)
  clCreateContextFromType(NULL, CL_DEVICE_TYPE_ACCELERATOR)  No devices found in platform
  clCreateContextFromType(NULL, CL_DEVICE_TYPE_CUSTOM)  No devices found in platform
  clCreateContextFromType(NULL, CL_DEVICE_TYPE_ALL)  Success (1)
    Platform Name                                 Clover
    Device Name                                   AMD CAPE VERDE (DRM 2.49.0 / 4.10.0-42-generic, LLVM 5.0.1)

ICD loader properties
  ICD loader Name                                 OpenCL ICD Loader
  ICD loader Vendor                               OCL Icd free software
  ICD loader Version                              2.2.8
  ICD loader Profile                              OpenCL 1.2
	NOTE:	your OpenCL library declares to support OpenCL 1.2,
		but it seems to support up to OpenCL 2.1 too.

```


## How to compile OpenCL example in GCC?  
Precisely, the kernel compilation in OpenCL is make in running time (library call).

In Gcc, for compilation, you only need the headers (aviables on Kronos site). But for linkage, you have to install OpenCL compatible driver.

* for Mac OSX : gcc filename.c -o filename -framework OpenCL
* for Linux : gcc/clang filename.c -o filename -/usr/lib/x86_64-linux-gnu/libOpenCL.so


ref: How to compile OpenCL example in GCC?  
https://forums.khronos.org/showthread.php/5728-How-to-compile-OpenCL-example-in-GCC
