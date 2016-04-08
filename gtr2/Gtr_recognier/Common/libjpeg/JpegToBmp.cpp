#include "JpegToBmp.h"
#include <stdio.h>
#include <Windows.h>
#include <QDataStream.h>
#include "jpeglib.h"
/*
bool JpegToBmp( const unsigned char *pSrc, int s_size, QByteArray &out )
{
	FILE *f_temp;
	if( (f_temp = fopen( "JT", "wb" )) == NULL )
		return false;
	fwrite( pSrc, s_size, 1, f_temp );
	fclose(f_temp);

	BITMAPFILEHEADER bfh;		// bmp�ļ�ͷ
	BITMAPINFOHEADER bih;		// bmpͷ��Ϣ
	RGBQUAD rq[256];			// ��ɫ��
	int nAdjust; // �����ֽڶ���

	BYTE *data= NULL;//new BYTE[bih.biWidth*bih.biHeight];
	//BYTE *pDataConv = NULL;//new BYTE[bih.biWidth*bih.biHeight];
	int nComponent = 0;

	// ������ѹ�����󼰴�����Ϣ������
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	if( (f_temp = fopen( "JT", "rb" )) == NULL )
		return false;

	jpeg_stdio_src(&cinfo, f_temp);//�ѵ�ֻ���Դ��ļ�װ��??
	jpeg_read_header(&cinfo, TRUE);
	nAdjust = cinfo.image_width*cinfo.num_components%4;
	if (nAdjust) nAdjust = 4-nAdjust;
	data = new BYTE[(cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height];	

	jpeg_start_decompress(&cinfo);

	JSAMPROW row_pointer[1];
	while (cinfo.output_scanline < cinfo.output_height)
	{
		row_pointer[0] = &data[(cinfo.output_height - cinfo.output_scanline-1)*(cinfo.image_width*cinfo.num_components+nAdjust)];
		jpeg_read_scanlines(&cinfo,row_pointer ,
			1);
	}
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	fclose(f_temp);

	QDataStream out_stream(&out,QIODevice::WriteOnly);
	// д�ļ�ͷ
	memset(&bfh,0,sizeof(bfh));
	bfh.bfSize = sizeof(bfh)+sizeof(bih);
	bfh.bfOffBits = sizeof(bfh)+sizeof(bih);
	if (cinfo.num_components==1)
	{
		bfh.bfOffBits += 1024;
		bfh.bfSize += 1024;
	}

	bfh.bfSize += (cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height;
	bfh.bfType = 0x4d42;
	//fwrite(&bfh,sizeof(bfh),1,f);
	out_stream.writeRawData((char*)&bfh,sizeof(bfh));

	// дͼ����Ϣ
	bih.biBitCount = cinfo.num_components*8;
	bih.biSize = sizeof(bih);
	bih.biWidth = cinfo.image_width;
	bih.biHeight = cinfo.image_height;
	bih.biPlanes = 1;
	bih.biCompression = 0;
	bih.biSizeImage = (cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height;
	bih.biXPelsPerMeter = 0;
	bih.biYPelsPerMeter = 0;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;
	//fwrite(&bih,sizeof(bih),1,f);
	out_stream.writeRawData((char*)&bih,sizeof(bih));
	// д��ɫ��
	if (cinfo.num_components ==1)
	{
		for (int i=0;i<256;i++)
		{
			rq[i].rgbBlue =i;
			rq[i].rgbGreen = i;
			rq[i].rgbRed = i;
			rq[i].rgbReserved = 0;
		}
		//fwrite(rq,1024,1,f);
		out_stream.writeRawData((char*)&rq,1024);
	}

	if (cinfo.num_components==3)
	{
		// ����rgb˳��
		for (int j=0;j<bih.biHeight;j++)
			for (int i = 0;i<bih.biWidth;i++)
			{
				BYTE red = data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3];
				data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3] = data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3+2];
				data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3+2] = red;
			}
	}
	//fwrite(data,(cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height,1,f);
	out_stream.writeRawData((char*)data,(cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height);
	delete [] data;

	return true;
}*/


bool JpegToBmp( QByteArray &in, QByteArray &out )
{
	BITMAPFILEHEADER bfh;		// bmp�ļ�ͷ
	BITMAPINFOHEADER bih;		// bmpͷ��Ϣ
	RGBQUAD rq[256];			// ��ɫ��
	int nAdjust; // �����ֽڶ���

	BYTE *data= NULL;//new BYTE[bih.biWidth*bih.biHeight];
	//BYTE *pDataConv = NULL;//new BYTE[bih.biWidth*bih.biHeight];
	int nComponent = 0;

	// ������ѹ�����󼰴�����Ϣ������
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	QDataStream in_stream(in);
	jpeg_stdio_src(&cinfo, &in_stream);//�ѵ�ֻ���Դ��ļ�װ��??
	jpeg_read_header(&cinfo, TRUE);
	nAdjust = cinfo.image_width*cinfo.num_components%4;
	if (nAdjust) nAdjust = 4-nAdjust;
	data = new BYTE[(cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height];	

	jpeg_start_decompress(&cinfo);

	JSAMPROW row_pointer[1];
	while (cinfo.output_scanline < cinfo.output_height)
	{
		row_pointer[0] = &data[(cinfo.output_height - cinfo.output_scanline-1)*(cinfo.image_width*cinfo.num_components+nAdjust)];
		jpeg_read_scanlines(&cinfo,row_pointer ,
			1);
	}
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	QDataStream out_stream(&out,QIODevice::WriteOnly);
	// д�ļ�ͷ
	memset(&bfh,0,sizeof(bfh));
	bfh.bfSize = sizeof(bfh)+sizeof(bih);
	bfh.bfOffBits = sizeof(bfh)+sizeof(bih);
	if (cinfo.num_components==1)
	{
		bfh.bfOffBits += 1024;
		bfh.bfSize += 1024;
	}

	bfh.bfSize += (cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height;
	bfh.bfType = 0x4d42;
	//fwrite(&bfh,sizeof(bfh),1,f);
	out_stream.writeRawData((char*)&bfh,sizeof(bfh));

	// дͼ����Ϣ
	bih.biBitCount = cinfo.num_components*8;
	bih.biSize = sizeof(bih);
	bih.biWidth = cinfo.image_width;
	bih.biHeight = cinfo.image_height;
	bih.biPlanes = 1;
	bih.biCompression = 0;
	bih.biSizeImage = (cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height;
	bih.biXPelsPerMeter = 0;
	bih.biYPelsPerMeter = 0;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;
	//fwrite(&bih,sizeof(bih),1,f);
	out_stream.writeRawData((char*)&bih,sizeof(bih));
	// д��ɫ��
	if (cinfo.num_components ==1)
	{
		for (int i=0;i<256;i++)
		{
			rq[i].rgbBlue =i;
			rq[i].rgbGreen = i;
			rq[i].rgbRed = i;
			rq[i].rgbReserved = 0;
		}
		//fwrite(rq,1024,1,f);
		out_stream.writeRawData((char*)&rq,1024);
	}

	if (cinfo.num_components==3)
	{
		// ����rgb˳��
		for (int j=0;j<bih.biHeight;j++)
			for (int i = 0;i<bih.biWidth;i++)
			{
				BYTE red = data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3];
				data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3] = data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3+2];
				data[j*(cinfo.image_width*cinfo.num_components+nAdjust)+i*3+2] = red;
			}
	}
	//fwrite(data,(cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height,1,f);
	out_stream.writeRawData((char*)data,(cinfo.image_width*cinfo.num_components+nAdjust)*cinfo.image_height);
	delete [] data;

	return true;
}