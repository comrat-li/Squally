#include "LightEffect.h"

#include "cocos/2d/CCSpriteFrame.h"

#include "Engine/Lighting/SmartSprite.h"

using namespace cocos2d;

LightEffect* LightEffect::create(std::string fragmentShader)
{
    LightEffect* instance = new (std::nothrow) LightEffect(fragmentShader);

    instance->autorelease();

    return instance;
}

LightEffect::LightEffect(std::string fragmentShader)
{
    this->initGLProgramState(fragmentShader);
    this->setLightColor(cocos2d::Color3B::WHITE);
    this->setAmbientLightColor(cocos2d::Color3B(127,127,127));
    this->setLightCutoffRadius(500.0f);
    this->setLightHalfRadius(0.5f);
}

LightEffect::~LightEffect()
{
}

void LightEffect::setLightPos(const Vec3 &pos)
{
    _lightPos = pos;
}

void LightEffect::setLightColor(const Color3B &color)
{
    _lightColor = color;
    getGLProgramState()->setUniformVec3("u_lightColor", Vec3(_lightColor.r,_lightColor.g,_lightColor.b)/255.0f);
}

void LightEffect::setAmbientLightColor(const Color3B &color)
{
    _ambientLightColor = color;
    getGLProgramState()->setUniformVec3("u_ambientColor", Vec3(_ambientLightColor.r,_ambientLightColor.g,_ambientLightColor.b)/255.0f);
}

void LightEffect::setBrightness(float value)
{
    _brightness = value;
    getGLProgramState()->setUniformFloat("u_brightness", value);
}

void LightEffect::setLightCutoffRadius(float value)
{
    _lightCutoffRadius = std::max(1.0f, value);
    getGLProgramState()->setUniformFloat("u_cutoffRadius", _lightCutoffRadius);
}

void LightEffect::setLightHalfRadius(float value)
{
    _lightHalfRadius = std::max(0.01f, std::min(0.99f, value));
    getGLProgramState()->setUniformFloat("u_halfRadius", _lightHalfRadius);
}

void LightEffect::prepareForRender(Sprite *sprite, Texture2D *normalmap)
{
    auto gl = getGLProgramState();

    gl->setUniformVec2("u_contentSize", sprite->getContentSize());

    Point posRelToSprite = PointApplyAffineTransform(Point(_lightPos.x, _lightPos.y), sprite->getWorldToNodeAffineTransform());
    gl->setUniformVec3("u_lightPos", Vec3(posRelToSprite.x, posRelToSprite.y, _lightPos.z));

    gl->setUniformTexture("u_normals", normalmap);

    SpriteFrame* frame = sprite->getSpriteFrame();
    Size untrimmedSize = frame->getOriginalSize();
    Size trimmedSize = frame->getRect().size;
    Vec2 framePos = frame->getRect().origin;
    Size texSize = frame->getTexture()->getContentSize();
    
    // set sprite position in sheet
    gl->setUniformVec2("u_spritePosInSheet", Vec2(framePos.x / texSize.width, framePos.y / texSize.height));
    gl->setUniformVec2("u_spriteSizeRelToSheet", Vec2(untrimmedSize.width / texSize.width, untrimmedSize.height / texSize.height));
    gl->setUniformInt("u_spriteRotated", frame->isRotated());
    
    // set offset of trimmed sprite
    Vec2 bottomLeft = frame->getOffset() + (untrimmedSize - trimmedSize) / 2;
    Vec2 cornerOffset = frame->isRotated() ? Vec2(bottomLeft.y, bottomLeft.x)
                                           : Vec2(bottomLeft.x, untrimmedSize.height - trimmedSize.height - bottomLeft.y);
    gl->setUniformVec2("u_spriteOffset", cornerOffset);
}
