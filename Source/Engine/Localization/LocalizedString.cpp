#include "LocalizedString.h"

#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/Events/LocalizationEvents.h"
#include "Engine/Localization/Localization.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/StrUtils.h"

using namespace cocos2d;

LocalizedString::LocalizedString()
{
	this->overrideLanguage = LanguageType::NONE;
	this->onStringUpdate = nullptr;
	this->stringReplacementVariables = std::vector<LocalizedString*>();
	this->currentLanguage = Localization::getLanguage();
}

LocalizedString::~LocalizedString()
{
}

void LocalizedString::onEnter()
{
	// ZAC: Optimization to skip SmartNode onEnter(). LocalizedStrings do not need the events set up by the SmartNode base class.
	// Less stuff to dispose, this means significantly faster map destruction.
	Node::onEnter();

	if (this->currentLanguage != Localization::getLanguage())
	{
		this->onStringUpdate(this);
	}

	// This needs to be done here since we side-step SmartNode functions
	this->addEventListenerIgnorePause(EventListenerCustom::create(LocalizationEvents::LocaleChangeEvent, [=](EventCustom* args)
	{
		if (this->onStringUpdate != nullptr)
		{
			this->onStringUpdate(this);
		}
	}));
}

std::string LocalizedString::getString()
{
	std::string localizedString;

	switch (this->overrideLanguage != LanguageType::NONE ? this->overrideLanguage : Localization::getLanguage())
	{
		case LanguageType::ARABIC:
		{
			localizedString = this->getStringAr();
			break;
		}
		case LanguageType::BULGARIAN:
		{
			localizedString = this->getStringBg();
			break;
		}
		case LanguageType::CHINESE_SIMPLIFIED:
		{
			localizedString = this->getStringZhCn();
			break;
		}
		case LanguageType::CHINESE_TRADITIONAL:
		{
			localizedString = this->getStringZhTw();
			break;
		}
		case LanguageType::CZECH:
		{
			localizedString = this->getStringCs();
			break;
		}
		case LanguageType::DANISH:
		{
			localizedString = this->getStringDa();
			break;
		}
		case LanguageType::DUTCH:
		{
			localizedString = this->getStringNl();
			break;
		}
		case LanguageType::FINNISH:
		{
			localizedString = this->getStringFi();
			break;
		}
		case LanguageType::FRENCH:
		{
			localizedString = this->getStringFr();
			break;
		}
		case LanguageType::GERMAN:
		{
			localizedString = this->getStringDe();
			break;
		}
		case LanguageType::GREEK:
		{
			localizedString = this->getStringEl();
			break;
		}
		case LanguageType::HUNGARIAN:
		{
			localizedString = this->getStringHu();
			break;
		}
		case LanguageType::ITALIAN:
		{
			localizedString = this->getStringIt();
			break;
		}
		case LanguageType::JAPANESE:
		{
			localizedString = this->getStringJa();
			break;
		}
		case LanguageType::KOREAN:
		{
			localizedString = this->getStringKo();
			break;
		}
		case LanguageType::NORWEGIAN:
		{
			localizedString = this->getStringNo();
			break;
		}
		case LanguageType::POLISH:
		{
			localizedString = this->getStringPl();
			break;
		}
		case LanguageType::PORTUGUESE:
		{
			localizedString = this->getStringPt();
			break;
		}
		case LanguageType::PORTUGUESE_BRAZIL:
		{
			localizedString = this->getStringPtBr();
			break;
		}
		case LanguageType::ROMANIAN:
		{
			localizedString = this->getStringRo();
			break;
		}
		case LanguageType::RUSSIAN:
		{
			localizedString = this->getStringRu();
			break;
		}
		case LanguageType::SPANISH:
		{
			localizedString = this->getStringEs();
			break;
		}
		case LanguageType::SPANISH_LATIN_AMERICAN:
		{
			localizedString = this->getStringEs419();
			break;
		}
		case LanguageType::SWEDISH:
		{
			localizedString = this->getStringSv();
			break;
		}
		case LanguageType::THAI:
		{
			localizedString = this->getStringTh();
			break;
		}
		case LanguageType::TURKISH:
		{
			localizedString = this->getStringTr();
			break;
		}
		case LanguageType::UKRAINIAN:
		{
			localizedString = this->getStringUk();
			break;
		}
		case LanguageType::VIETNAMESE:
		{
			localizedString = this->getStringVi();
			break;
		}
		case LanguageType::ENGLISH:
		default:
		{
			localizedString = this->getStringEn();
			break;
		}
	}

	int index = 1;

	for (auto it = this->stringReplacementVariables.begin(); it != this->stringReplacementVariables.end(); it++)
	{
		if (*it != nullptr)
		{
			localizedString = StrUtils::replaceAll(localizedString, "%s" + std::to_string(index++), (*it)->getString());
		}
		else
		{
			localizedString = StrUtils::replaceAll(localizedString, "%s" + std::to_string(index++), "");
		}
	}

	return localizedString;
}

cocos2d::LanguageType LocalizedString::getOverrideLanguage()
{
	return this->overrideLanguage;
}

void LocalizedString::setOverrideLanguage(cocos2d::LanguageType overrideLanguage)
{
	this->overrideLanguage = overrideLanguage;
}

LocalizedString* LocalizedString::setStringReplacementVariables(LocalizedString* stringReplacementVariables)
{
	return this->setStringReplacementVariables(std::vector<LocalizedString*>({ stringReplacementVariables }));
}

LocalizedString* LocalizedString::setStringReplacementVariables(std::vector<LocalizedString*> stringReplacementVariables)
{
	// Release old replacement varaibles
	for (auto it = this->stringReplacementVariables.begin(); it != this->stringReplacementVariables.end(); it++)
	{
		if (*it == nullptr)
		{
			continue;
		}

		bool isReentry = false;

		for (auto compareIt = stringReplacementVariables.begin(); compareIt != stringReplacementVariables.end(); compareIt++)
		{
			if (*it == *compareIt)
			{
				isReentry = true;
			}
		}

		if (isReentry)
		{
			// Remove the child and retain it
			GameUtils::changeParent(*it, nullptr, true, false);
		}
		else
		{
			// Remove the child and release it
			this->removeChild(*it);
		}
	}

	this->stringReplacementVariables = stringReplacementVariables;

	// Retain new replacement variables
	for (auto it = this->stringReplacementVariables.begin(); it != this->stringReplacementVariables.end(); it++)
	{
		if (*it == nullptr)
		{
			continue;
		}

		// Update this string if any of the replacement variables get updated
		(*it)->setOnStringUpdateCallback([=](LocalizedString*)
		{
			if (this->onStringUpdate != nullptr)
			{
				this->onStringUpdate(this);
			}
		});
		
		this->addChild(*it);
	}

	if (this->onStringUpdate != nullptr)
	{
		this->onStringUpdate(this);
	}

	return this;
}

void LocalizedString::setOnStringUpdateCallback(std::function<void(LocalizedString* newString)> onStringUpdate)
{
	this->onStringUpdate = onStringUpdate;
}

void LocalizedString::copyAttributesTo(LocalizedString* localizedString)
{
	localizedString->setOverrideLanguage(this->getOverrideLanguage());

	std::vector<LocalizedString*> stringReplacementVariables = std::vector<LocalizedString*>();

	for (auto it = this->stringReplacementVariables.begin(); it != this->stringReplacementVariables.end(); it++)
	{
		stringReplacementVariables.push_back(*it == nullptr ? nullptr : (*it)->clone());
	}

	localizedString->setStringReplacementVariables(stringReplacementVariables);
}
