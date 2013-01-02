#
# Makefile for GNU/Linux
#

CPP = g++
ZIP = zip
ECHO = echo

PK4 = zeta-0.01-linux.pk4

CPPFLAGS = -fPIC -pipe -Wall -Wno-unknown-pragmas -fmessage-length=0 \
	-fpermissive -fvisibility=hidden -m32 -O3 -march=pentium3 \
	-Winline -ffast-math -fno-unsafe-math-optimizations \
	-fomit-frame-pointer -fno-strict-aliasing

BOT_OBJS = \
	Adapter.o \
	Adapter_D3.o \
	BotCommon.o \
	Bot.o \
	Bot_D3.o \
	BotFacade.o \
	BotService.o \
	BotService_D3.o \
	EngineAPI.o \
	Export.o \
	GameAPI.o \
	Glue.o \
	Stub.o \
	SysCmds.o \
	Unzip.o

IDLIB_OBJS = \
	../idlib/Base64.o \
	../idlib/BitMsg.o \
	../idlib/CmdArgs.o \
	../idlib/Dict.o \
	../idlib/Heap.o \
	../idlib/LangDict.o \
	../idlib/Lexer.o \
	../idlib/Lib.o \
	../idlib/MapFile.o \
	../idlib/Parser.o \
	../idlib/Str.o \
	../idlib/Timer.o \
	../idlib/Token.o \
	../idlib/bv/Bounds.o \
	../idlib/bv/Box.o \
	../idlib/bv/Frustum.o \
	../idlib/bv/Frustum_gcc.o \
	../idlib/bv/Sphere.o \
	../idlib/containers/HashIndex.o \
	../idlib/geometry/DrawVert.o \
	../idlib/geometry/JointTransform.o \
	../idlib/geometry/Surface.o \
	../idlib/geometry/Surface_Patch.o \
	../idlib/geometry/Surface_Polytope.o \
	../idlib/geometry/Surface_SweptSpline.o \
	../idlib/geometry/TraceModel.o \
	../idlib/geometry/Winding.o \
	../idlib/geometry/Winding2D.o \
	../idlib/hashing/CRC32.o \
	../idlib/hashing/MD4.o \
	../idlib/hashing/MD5.o \
	../idlib/math/Angles.o \
	../idlib/math/Complex.o \
	../idlib/math/Lcp.o \
	../idlib/math/Math.o \
	../idlib/math/Matrix.o \
	../idlib/math/Ode.o \
	../idlib/math/Plane.o \
	../idlib/math/Pluecker.o \
	../idlib/math/Polynomial.o \
	../idlib/math/Quat.o \
	../idlib/math/Rotation.o \
	../idlib/math/Simd.o \
	../idlib/math/Simd_3DNow.o \
	../idlib/math/Simd_Generic.o \
	../idlib/math/Simd_MMX.o \
	../idlib/math/Simd_SSE.o \
	../idlib/math/Simd_SSE2.o \
	../idlib/math/Simd_SSE3.o \
	../idlib/math/Vector.o \
	../idlib/precompiled.o

OBJS = ${IDLIB_OBJS} ${BOT_OBJS}

all: ${PK4}

${PK4}: gamex86.so binary.conf
	${ZIP} -9 ${PK4} gamex86.so binary.conf

gamex86.so: ${OBJS}
	${CPP} -m32 -shared -o $@ ${OBJS} -ldl -lm

binary.conf:
	${ECHO} 2 >binary.conf

clean:
	-$(RM) ${OBJS}
	-$(RM) gamex86.so
	-$(RM) binary.conf
	-$(RM) ${PK4}

distclean:	clean

%.o:	%.cpp
	${CPP} ${CPPFLAGS} -c $< -o $@
