/*
 * This file is part of the CN24 semantic segmentation software,
 * copyright (C) 2015 Clemens-Alexander Brust (ikosa dot de at gmail dot com).
 *
 * For licensing information, see the LICENSE file included with this project.
 */  
/**
 * \file Init.h
 * \brief Provides initialization functions for several subsystems
 *
 * \author Clemens-A. Brust (ikosa.de@gmail.com)
 */

#ifndef CONV_INIT_H
#define CONV_INIT_H

#include "TensorViewer.h"

#ifdef BUILD_OPENCL
#include <CL/cl.h>
#include <string>
#endif

namespace Conv {
class System {
public:
  static void Init();
#ifdef BUILD_OPENCL
  static cl_program CreateProgram(const char* file_name);
  static cl_device_id device;
  static cl_context context;
  static cl_command_queue queue;
  
  // Kernels
  static cl_kernel k_crossCorrelation;
  static cl_kernel k_biasedConvolution;
  static cl_kernel k_fullConvolution;
  static cl_kernel k_biasedMatrixVector;
  static cl_kernel k_biasedMatrixVectorGrad;
  static cl_kernel k_biasedMatrixVectorBackward;
  static cl_kernel k_biasGradientPart1;
  static cl_kernel k_biasGradientPart2;
  static cl_kernel k_matrixMatrix;
  static cl_kernel k_foldWeights;
  static cl_kernel k_maximumForward;
  static cl_kernel k_maximumBackward;
  static cl_kernel k_nlTanh;
  static cl_kernel k_nlTanhBackward;
  static cl_kernel k_nlSigm;
  static cl_kernel k_nlSigmBackward;
#endif
  static TensorViewer* viewer;
};
  
}

#endif