#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <torch/script.h> 
#include <torch/torch.h>
#include <opencv2/opencv.hpp>
#include "trail_header.hpp"

#ifdef USE_CUDA
#include "gpu.hpp"
#endif

using namespace std;
using namespace cv;

int main()
{
    std::cout << "Hello, world!" << std::endl;

#ifdef USE_CUDA
    std::cout << "CUDA: On" << std::endl;
    printCudaVersion();
#else
    std::cout << "CUDA: Off" << std::endl;
#endif

    std::cout << __cplusplus << std::endl;

    // import from class
    // testHeaderImport trail;
    // std::cout << trail.name << std::endl;
    // trail.setName("Shubham");
    // std::cout << trail.name << std::endl;

    std::cout << "PyTorch version: "
        << TORCH_VERSION_MAJOR << "."
        << TORCH_VERSION_MINOR << "."
        << TORCH_VERSION_PATCH << std::endl;

    torch::Tensor tensor = torch::eye(3);
    std::cout << tensor << std::endl;


    torch::Device device = torch::kCPU;
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Training on GPU." << std::endl;
    device = torch::kCUDA;
    }
    else {
        std::cout << "CUDA is not available" << std::endl;
    }


    printf("OpenCV: %s", cv::getBuildInformation().c_str());

    return 0;
}
