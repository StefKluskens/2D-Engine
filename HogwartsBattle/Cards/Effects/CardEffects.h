#pragma once

namespace Engine
{
	class GameObject;
}

namespace HB
{
	class CardEffects
	{
	public:
		CardEffects();
		virtual ~CardEffects() = default;
		CardEffects(const CardEffects& other) = delete;
		CardEffects(CardEffects&& other) noexcept = delete;
		CardEffects& operator=(const CardEffects& other) = delete;
		CardEffects& operator=(CardEffects&& other) = delete;

		virtual void PlayEffect(Engine::GameObject* pObject) = 0;
	};

	class LoseHealthEffect final : public CardEffects
	{
	public:
		LoseHealthEffect(int healthToLose);
		virtual ~LoseHealthEffect() = default;
		LoseHealthEffect(const LoseHealthEffect& other) = delete;
		LoseHealthEffect(LoseHealthEffect&& other) noexcept = delete;
		LoseHealthEffect& operator=(const LoseHealthEffect& other) = delete;
		LoseHealthEffect& operator=(LoseHealthEffect&& other) = delete;

		virtual void PlayEffect(Engine::GameObject* pObject) override;

	private:
		int m_HealthToLose;
	};

	class AddControlEffect : public CardEffects
	{
	public:
		AddControlEffect(int amountOfControl);
		virtual ~AddControlEffect() = default;
		AddControlEffect(const AddControlEffect& other) = delete;
		AddControlEffect(AddControlEffect&& other) noexcept = delete;
		AddControlEffect& operator=(const AddControlEffect& other) = delete;
		AddControlEffect& operator=(AddControlEffect&& other) = delete;

		virtual void PlayEffect(Engine::GameObject* pObject) override;

	private:
		int m_ControlToAdd{};
	};

	/*class DiscardEffect : public CardEffects
	{
	public:
		DiscardEffect();
		virtual ~DiscardEffect() = default;
		DiscardEffect(const DiscardEffect& other) = delete;
		DiscardEffect(DiscardEffect&& other) noexcept = delete;
		DiscardEffect& operator=(const DiscardEffect& other) = delete;
		DiscardEffect& operator=(DiscardEffect&& other) = delete;

		virtual void PlayEffect() override;
	};

	

	class NoDrawingEffect : public CardEffects
	{
	public:
		NoDrawingEffect();
		virtual ~NoDrawingEffect() = default;
		NoDrawingEffect(const NoDrawingEffect& other) = delete;
		NoDrawingEffect(NoDrawingEffect&& other) noexcept = delete;
		NoDrawingEffect& operator=(const NoDrawingEffect& other) = delete;
		NoDrawingEffect& operator=(NoDrawingEffect&& other) = delete;

		virtual void PlayEffect() override;
	};*/
}