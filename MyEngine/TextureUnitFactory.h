#ifndef TextureUnitFactory_H
#define TextureUnitFactory_H

namespace Entities
{
	class SARendererComponent;
}

class TextureUnitFactory
{
public:
	TextureUnitFactory();
	~TextureUnitFactory();

	int GetTextureUnit(Entities::SARendererComponent* renderer);
};

#endif