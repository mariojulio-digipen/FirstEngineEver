#ifndef GLObjectFactory_H
#define GLObjectFactory_H


#include <string>
#include <vector>

class GLObjectBase;

class GLObjectFactory
{
private:

	GLObjectBase* glObject;


	std::vector<float> vertexes;
	int numVerts;

public:
	GLObjectFactory();
	~GLObjectFactory();

	GLObjectBase* GLObject(std::string graphicType, int textureUnit);
	void InitVers(std::string texturePath);

};

#endif