#include "imagemanager.h"

ImageManager::ImageManager()
{
}
ImageManager::~ImageManager()
{
}


 ImageManager &ImageManager::GetInstance()
 {
 	static ImageManager instance;
 	return instance;
 }

void ImageManager::AddMbkImage(const MbkImage &mbkImage)
{
	DeleteMbkImage( mbkImage.NO );
	m_MbkImages.push_back(mbkImage);
}

void ImageManager::DeleteMbkImage(const QString &NO)
{
	for( std::vector<MbkImage>::iterator it = m_MbkImages.begin(); it!=m_MbkImages.end(); )
	{
		if(it->NO==NO)
			it = m_MbkImages.erase(it);
		else
			++it;
	}
}


MbkImage* ImageManager::GetMbkImage(const QString &NO)
{
	for(int i=0;i<m_MbkImages.size();i++)
	{
		if(m_MbkImages[i].NO == NO)
			return &m_MbkImages[i];
	}

	return NULL;
}

void ImageManager::AddYzmImage(const YzmImage &yzmImage)
{
	DeleteYzmImage(yzmImage.NO);
	m_YzmImages.push_back(yzmImage);
}

void ImageManager::DeleteYzmImage(const QString &NO)
{
	for( std::vector<YzmImage>::iterator it = m_YzmImages.begin(); it!=m_YzmImages.end(); )
	{
		if(it->NO==NO)
			it = m_YzmImages.erase(it);
		else
			++it;
	}
}


YzmImage* ImageManager::GetYzmImage(const QString &NO)
{
	for( int i=0; i<m_YzmImages.size(); i++ )
	{
		if(m_YzmImages[i].NO == NO)
			return &m_YzmImages[i];
	}

	return NULL;
}
int ImageManager::MbkNumber()const
{
	return m_MbkImages.size();
}
int	ImageManager::YzmNumber()const
{
	return m_YzmImages.size();
}