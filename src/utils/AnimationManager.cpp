#include <utils/AnimationManager.hpp> // utils::AnimationManager
#include <schemas/animations.hpp> // from flatbuffers schema for animations (generated by flatc)
#include <GUI/game/Animation.hpp> // gui::Animation
#include <fstream> // std::ifstream
#include <iostream> // std::cout

namespace utils
{
	AnimationManager::AnimationManager()
		: _animations(), _specials() {}

	AnimationManager::~AnimationManager() noexcept
	{
		for (auto& animation : _animations)
		{
			delete animation;
		}

		for (auto& [type, animations] : _specials)
		{
			for (auto& [name, animation] : animations)
			{
				delete animation;
			}
		}
	}

	void AnimationManager::loadAnimations()
	{
		std::ifstream infile("assets/data/animations.bin", std::ios::binary | std::ios::in);
		infile.seekg(0, std::ios::end);
		
		std::streampos length = infile.tellg();
		infile.seekg(0, std::ios::beg);
		char* buffer = new char[length];
		
		infile.read(buffer, length);
		infile.close();

		auto animations_list = GetAnimationRoot(buffer)->animations();
		auto special_animations_list = GetAnimationRoot(buffer)->specials();

		_animations.reserve(animations_list->size());

		for (const Animation* const& animation : *animations_list)
		{
			gui::Animation* new_animation = new gui::Animation;

			for (const Frame* const& frame : *animation->frames())
			{
				new_animation->addFrame(frame->left(), frame->top(), frame->width(), frame->height());
			}

			_animations.push_back(new_animation);
		}

		for (const Set* const& set : *special_animations_list)
		{
			for (const Animation* const& animation : *set->animations())
			{
				gui::Animation* new_animation = new gui::Animation;

				for (const Frame* const& frame : *animation->frames())
				{
					new_animation->addFrame(frame->left(), frame->top(), frame->width(), frame->height());
				}
				
				_specials[set->type()->data()][animation->name()->data()] = new_animation;
			}
		}
		
		delete[] buffer;
	}

	const std::vector<gui::Animation*>& AnimationManager::getAnimations() const
	{
		return _animations;
	}

	const std::map<std::string, gui::Animation*>& AnimationManager::getSpecialAnimations(std::string_view type) const
	{
		return _specials.at(type.data());
	}

	const gui::Animation* AnimationManager::getSpecialAnimation(std::string_view type, std::string_view name) const
	{
		return _specials.at(type.data()).at(name.data());
	}
}
