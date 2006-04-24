if    [  -f  $CONFIG_CACHE/host.def  ];  then
  cp     $CONFIG_CACHE/host.def  config/cf/host.def
fi  &&

if [ -f config/cf/host.def ];  then
  sedit s"/-Os//g" config/cf/host.def
fi  &&

message  "Building XFree86 takes a very long time."

if  (echo $CFLAGS | grep -q -- "-Os");  then
    export CFLAGS="-O2 ${CFLAGS//-Os/}"
fi  &&

#disable bad libs
cat <<__EOF__ >config/cf/site.def

#define DefaultCCOptions      $CFLAGS
#define DefaultGcc2i386Opt    $CFLAGS
#define LibraryCDebugFlags    $CFLAGS
#define DefaultCDebugFlags    $CFLAGS
#define ProjectRoot           /usr/X11R6
#define HasShm                   YES
#define HasZlib                  YES
#define HasFreetype2             YES
#define BuildFreetype2Library     NO
#define HasExpat                 YES
#define HasFontconfig            YES

#define BuildXInputLib          YES
#define XInputDrivers mouse keyboard
#define BuildXInputExt          YES
#define	BuildServer		  NO
#define BuildFontServer		  NO
#define BuildXAServer		  NO
#define BuildLBX		  NO
#define BuildXF86VidModeLibrary	  YES
#define BuildPlugin		  NO
#define BuildCID		  NO
#define BuildDPSClients		  NO
#define BuildServersOnly	  NO
#define	BuildClients		  NO

#define BuildFonts                NO
#define BuildSpeedoFonts          NO
#define	BuildType1Fonts           NO
#define BuildCIDFonts             NO
#define	BuildTTFonts              NO
#define	BuildPexExt               NO

#define BuildMiscDocs             NO
#define BuildSpecsDocs            NO

#define BuildXaw6                 YES
#define	BuildXKB                  NO
#define BuildLBX                  NO

#define BuildXIElib		YES
#define BuildPexLib		YES
#define BuildXF86MiscLibrary	YES
#define BuildXvLibrary		YES
#define BuildXResLibrary	YES
#define BuildGLXLibrary		YES
#define BuildGLwLibrary		YES
#define BuildGLULibrary		YES
#define BuildRenderLibrary	YES
#define BuildXF86MiscLibrary	YES
#define BuildRandRLibrary	YES
#define BuildXTrapLibrary	YES
#define BuildX11Lib		YES
#define BuildXprintLib		YES
#define BuildXextLib		YES
#define BuildThreadStubLibrary	YES
#define BuildLibraries		YES

#define DriDrivers              /**/
#define BuildXF86DRM            NO

__EOF__
# end 

cd config/util                                   &&
make -f Makefile.ini lndir                       &&
cp lndir $SOURCE_DIRECTORY.bld/                  &&
cd $SOURCE_DIRECTORY.bld                         &&
./lndir ../xc/                                   &&

make  World
