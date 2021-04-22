# Install script for directory: F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/nori")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/GAMES202/Assignment2/prt/build/ext_build/openexr/OpenEXR/IlmImf/Debug/IlmImf.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/GAMES202/Assignment2/prt/build/ext_build/openexr/OpenEXR/IlmImf/Release/IlmImf.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/GAMES202/Assignment2/prt/build/ext_build/openexr/OpenEXR/IlmImf/MinSizeRel/IlmImf.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/GAMES202/Assignment2/prt/build/ext_build/openexr/OpenEXR/IlmImf/RelWithDebInfo/IlmImf.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenEXR" TYPE FILE FILES
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfForward.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfExport.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfBoxAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfCRgbaFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfChannelList.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfChannelListAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfCompressionAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDoubleAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfFloatAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfFrameBuffer.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfHeader.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfIO.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfInputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfIntAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfLineOrderAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfMatrixAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfOpaqueAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfOutputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfRgbaFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfStringAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfVecAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfHuf.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfWav.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfLut.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfArray.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfCompression.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfLineOrder.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfName.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfPixelType.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfVersion.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfXdr.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfConvert.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfPreviewImage.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfPreviewImageAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfChromaticities.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfChromaticitiesAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfKeyCode.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfKeyCodeAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTimeCode.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTimeCodeAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfRational.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfRationalAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfFramesPerSecond.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfStandardAttributes.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfEnvmap.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfEnvmapAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfInt64.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfRgba.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTileDescription.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTileDescriptionAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTiledInputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTiledOutputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTiledRgbaFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfRgbaYca.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTestFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfThreading.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfB44Compressor.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfStringVectorAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfMultiView.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfAcesFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfMultiPartOutputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfGenericOutputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfMultiPartInputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfGenericInputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfPartType.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfPartHelper.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfOutputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTiledOutputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfInputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfTiledInputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineOutputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineOutputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineInputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineInputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledInputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledInputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledOutputFile.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledOutputPart.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepFrameBuffer.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepCompositing.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfCompositeDeepScanLine.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfNamespace.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfMisc.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepImageState.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfDeepImageStateAttribute.h"
    "F:/GAMES202/Assignment2/prt/ext/openexr/OpenEXR/IlmImf/ImfFloatVectorAttribute.h"
    )
endif()

