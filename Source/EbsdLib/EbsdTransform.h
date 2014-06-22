/* ============================================================================
 * Copyright (c) 2011 Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2011 Dr. Michael A. Groeber (US Air Force Research Laboratories)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of Michael A. Groeber, Michael A. Jackson, the US Air Force,
 * BlueQuartz Software nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  This code was written under United States Air Force Contract number
 *                           FA8650-07-D-5800
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifndef _EBSDTRANSFORM_H_
#define _EBSDTRANSFORM_H_

#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtCore/QMap>

#include "EbsdLib/EbsdSetGetMacros.h"
#include "EbsdLib/EbsdLib.h"
#include "EbsdLib/EbsdConstants.h"
#include "EbsdLib/EbsdHeaderEntry.h"




/**
 * @class EbsdTransform EbsdTransform.h EbsdLib/EbsdTransform.h
 * @brief This class is the super class to transform an Ebsd data file. This class is
 * meant to be subclassed for each manufacturer so that custom transformations
 * can be written for those data files. The current subclasses are for TSL (.ang)
 * and HKL (.ctf) data files and their HDF5 versions also.
 *
 * @author Michael A. Jackson for BlueQuartz Software
 * @date Aug 24, 2011
 * @version 1.0
 */
class EbsdLib_EXPORT EbsdTransform
{
  public:
    EbsdTransform();
    EBSD_TYPE_MACRO(EbsdTransform)

    virtual ~EbsdTransform();



    /**
     * @brief IdentifyStandardTransformation: Identifies which transformation (TSL, HKL, HEDM, etc) based on the the ...
     * @param sampleTransformation
     * @param eulerTransformation
     * @return
     */
    static Ebsd::EbsdToSampleCoordinateMapping IdentifyStandardTransformation(AxisAngleInput_t sampleTransformation, AxisAngleInput_t eulerTransformation);


  protected:



  private:
    EbsdTransform(const EbsdTransform&); // Copy Constructor Not Implemented
    void operator=(const EbsdTransform&); // Operator '=' Not Implemented

};

#endif /* EBSDTRANSFORM_H_ */
