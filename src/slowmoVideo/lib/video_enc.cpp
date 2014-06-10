#include "config.h"

#include "video_enc.h"

VideoWriter* CreateVideoWriter( const char* filename, int width, int height,double fps,int use_qt)
{
#ifdef USE_QTKIT
	VideoWriter* driver= CreateVideoWriter_QT(filename,width, height,fps);
#endif
#ifdef USE_FFMPEG
	VideoWriter* driver= CreateVideoWriter_FFMPEG(filename,width, height,fps);
#endif
	return driver;
}

int WriteFrame( VideoWriter* writer, const QImage& frame)
{
    return writer ? writer->writeFrame(frame) : 0;
}

void ReleaseVideoWriter( VideoWriter** pwriter )
{
    if( pwriter && *pwriter ) {
        delete *pwriter;
        *pwriter = 0;
    }
}
