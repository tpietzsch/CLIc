/*  CLIc - version 0.1 - Copyright 2020 Stéphane Rigaud, Robert Haase,
*   Institut Pasteur Paris, Max Planck Institute for Molecular Cell Biology and Genetics Dresden
*
*   CLIc is part of the clEsperanto project http://clesperanto.net 
*
*   This file is subject to the terms and conditions defined in
*   file 'LICENSE.txt', which is part of this source code package.
*/


#include "cleGreaterConstantKernel.h"

namespace cle
{
    
void GreaterConstantKernel::DefineDimensionality()
{
    std::string dim = "_2d";
    Buffer* bufferObject = dynamic_cast<Buffer*>(parameterList.at("src"));
    if(bufferObject->GetDimensions()[2] > 1)
    {
        dim = "_3d";
    }
    kernelName = kernelName + dim;
}

void GreaterConstantKernel::SetInput(Object& x)
{
    this->AddObject(&x, "src1");
}

void GreaterConstantKernel::SetOutput(Object& x)
{
    this->AddObject(&x, "dst");
}

void GreaterConstantKernel::SetScalar(float x)
{
    Float* val = new Float(x);
    this->AddObject(val, "scalar");
}

void GreaterConstantKernel::Execute()
{
    DefineDimensionality();
    CompileKernel();
    AddArgumentsToKernel();
    DefineRangeKernel();
}

} // namespace cle
