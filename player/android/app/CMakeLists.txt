cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../code")

add_definitions(-DDEBUG=1)
add_definitions(-D_DEBUG=1)
add_definitions(-DZLIB_DEBUG)
add_definitions(-DPNG_ARM_NEON_OPT=0)
add_definitions(-DHAVE_UNISTD_H)
add_definitions(-DLUA_COMPAT_5_3)
add_definitions(-DMAKE_LIB)
add_definitions(-DFREETYPE_ENABLED)
add_definitions(-DFT2_BUILD_LIBRARY)
add_definitions(-DFT_CONFIG_OPTION_USE_PNG)

file(GLOB_RECURSE SOURCE_FILES_GAME
  ${PROJ_DIR}/game/*.cpp
)

file(GLOB_RECURSE SOURCE_FILES_GAMEPLAY
  ${PROJ_DIR}/gameplay/*.cpp
)

file(GLOB_RECURSE SOURCE_FILES_BOX2D
  ${PROJ_DIR}/thirdparty/Box2D/*.cpp
)

file(GLOB_RECURSE SOURCE_FILES_BULLET
  ${PROJ_DIR}/thirdparty/bullet/Bullet3Common/*.cpp
  ${PROJ_DIR}/thirdparty/bullet/BulletCollision/*.cpp
  ${PROJ_DIR}/thirdparty/bullet/BulletDynamics/*.cpp
  ${PROJ_DIR}/thirdparty/bullet/BulletInverseDynamics/*.cpp
  ${PROJ_DIR}/thirdparty/bullet/BulletSoftBody/*.cpp
  ${PROJ_DIR}/thirdparty/bullet/LinearMath/*.cpp
)

file(GLOB SOURCE_FILES_OPENAL
  ${PROJ_DIR}/thirdparty/openal/common/*.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/*.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/backends/base.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/backends/loopback.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/backends/null.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/backends/opensl.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/effects/*.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/filters/*.cpp
  ${PROJ_DIR}/thirdparty/openal/Alc/mixer/*.cpp
  ${PROJ_DIR}/thirdparty/openal/OpenAL32/*.cpp
)

file(GLOB_RECURSE SOURCE_FILES_LUA
  ${PROJ_DIR}/thirdparty/lua/onelua.c
)

file(GLOB_RECURSE SOURCE_FILES_OGG
  ${PROJ_DIR}/thirdparty/ogg/src/*.c
)

file(GLOB_RECURSE SOURCE_FILES_VORBIS
  ${PROJ_DIR}/thirdparty/vorbis/lib/*.c
)

file(GLOB_RECURSE SOURCE_FILES_PNG
  ${PROJ_DIR}/thirdparty/png/*.c
)

file(GLOB_RECURSE SOURCE_FILES_ZLIB
  ${PROJ_DIR}/thirdparty/zlib/*.c
)

file(GLOB_RECURSE SOURCE_FILES_FREETYPE
  ${PROJ_DIR}/thirdparty/freetype/src/autofit/autofit.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftbase.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftbbox.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftbdf.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftbitmap.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftcid.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftdebug.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftfstype.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftgasp.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftglyph.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftgxval.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftinit.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftmm.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftotval.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftpatent.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftpfr.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftstroke.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftsynth.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftsystem.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/fttype1.c
  ${PROJ_DIR}/thirdparty/freetype/src/base/ftwinfnt.c
  ${PROJ_DIR}/thirdparty/freetype/src/bdf/bdf.c
  ${PROJ_DIR}/thirdparty/freetype/src/bzip2/ftbzip2.c
  ${PROJ_DIR}/thirdparty/freetype/src/cache/ftcache.c
  ${PROJ_DIR}/thirdparty/freetype/src/cff/cff.c
  ${PROJ_DIR}/thirdparty/freetype/src/cid/type1cid.c
  ${PROJ_DIR}/thirdparty/freetype/src/gxvalid/gxvalid.c
  ${PROJ_DIR}/thirdparty/freetype/src/gzip/ftgzip.c
  ${PROJ_DIR}/thirdparty/freetype/src/lzw/ftlzw.c
  ${PROJ_DIR}/thirdparty/freetype/src/otvalid/otvalid.c
  ${PROJ_DIR}/thirdparty/freetype/src/pcf/pcf.c
  ${PROJ_DIR}/thirdparty/freetype/src/pfr/pfr.c
  ${PROJ_DIR}/thirdparty/freetype/src/psaux/psaux.c
  ${PROJ_DIR}/thirdparty/freetype/src/pshinter/pshinter.c
  ${PROJ_DIR}/thirdparty/freetype/src/psnames/psnames.c
  ${PROJ_DIR}/thirdparty/freetype/src/raster/raster.c
  ${PROJ_DIR}/thirdparty/freetype/src/sfnt/sfnt.c
  ${PROJ_DIR}/thirdparty/freetype/src/smooth/smooth.c
  ${PROJ_DIR}/thirdparty/freetype/src/truetype/truetype.c
  ${PROJ_DIR}/thirdparty/freetype/src/type1/type1.c
  ${PROJ_DIR}/thirdparty/freetype/src/type42/type42.c
  ${PROJ_DIR}/thirdparty/freetype/src/winfonts/winfnt.c
)

file(GLOB_RECURSE SOURCE_FILES_GLUE
  ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c
)

add_library(
  gameplay SHARED

  ${SOURCE_FILES_GAME}
  ${SOURCE_FILES_GAMEPLAY}
  ${SOURCE_FILES_BOX2D}
  ${SOURCE_FILES_BULLET}
  ${SOURCE_FILES_OPENAL}
  ${SOURCE_FILES_LUA}
  ${SOURCE_FILES_OGG}
  ${SOURCE_FILES_VORBIS}
  ${SOURCE_FILES_PNG}
  ${SOURCE_FILES_ZLIB}
  ${SOURCE_FILES_FREETYPE}
  ${SOURCE_FILES_GLUE}
)

target_include_directories(
  gameplay PRIVATE
  .
  ${PROJ_DIR}
  ${PROJ_DIR}/game
  ${PROJ_DIR}/gameplay
  ${PROJ_DIR}/thirdparty
  ${PROJ_DIR}/thirdparty/Box2D
  ${PROJ_DIR}/thirdparty/bullet
  ${PROJ_DIR}/thirdparty/openal
  ${PROJ_DIR}/thirdparty/openal/include
  ${PROJ_DIR}/thirdparty/openal/common
  ${PROJ_DIR}/thirdparty/openal/Alc
  ${PROJ_DIR}/thirdparty/openal/OpenAL32/Include
  ${PROJ_DIR}/thirdparty/lua
  ${PROJ_DIR}/thirdparty/ogg/include
  ${PROJ_DIR}/thirdparty/vorbis/include
  ${PROJ_DIR}/thirdparty/vorbis/lib
  ${PROJ_DIR}/thirdparty/png
  ${PROJ_DIR}/thirdparty/zlib
  ${PROJ_DIR}/thirdparty/freetype/include
  ${ANDROID_NDK}/sources/android/native_app_glue
)

# add lib dependencies
target_link_libraries(
  gameplay
  android
  EGL
  GLESv2
  OpenSLES
  log
)
