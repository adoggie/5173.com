#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "imagetype.h"

class ImageManager
{
public:
	~ImageManager();
	static ImageManager &GetInstance();

	int MbkNumber()const;
	int	YzmNumber()const;

	void AddMbkImage(const MbkImage &mbkImage);
	void DeleteMbkImage(const QString &NO);
	MbkImage* GetMbkImage(const QString &NO);

	void AddYzmImage(const YzmImage &yzmImage);
	void DeleteYzmImage(const QString &NO);
	YzmImage* GetYzmImage(const QString &NO);
private:
	ImageManager();

	std::vector<MbkImage> m_MbkImages;
	std::vector<YzmImage> m_YzmImages;
};

#endif // IMAGEMANAGER_H
