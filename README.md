# Template to Run C++ with Boost, OpenCV, and Libtorch

## Download dependencies

Using CUDA 11.3 with CUDnn 8.6 with `sm_86` architecture.

### Install Boost
```
sudo apt install libboost-program-options-dev
```

## DownLoad CUDA and CUDnn from the Nvidia website
```
TODO: Add detailed instructions
```

### Install OpenCV 4.5
```
TODO: Write the instructions
```

### Install LibTorch for CUDA 11.3 and CUDnn > 7.0

As of 12/4/2022, PyTorch website has removed the instructions to fetch LibTorch for CUDA 11.3. Follow this instructions:

```
wget libtorch-cxx11-abi-shared-with-deps-1.10.1+cu113.zip : https://download.pytorch.org/libtorch/cu113/libtorch-cxx11-abi-shared-with-deps-1.10.1%2Bcu113.zip
```

UnZip the file and provide the path for CMake
```
unzip libtorch-cxx11-abi-shared-with-deps-1.10.1+cu113.zip
```

## To run the folder
```
mkdir build && cd build
```

Then use `cmake`
```
cmake ..
```

followed by

```
make -j4
```
