#include "../headers/Animator.h"

Animator::Animator(sf::Sprite &parentSprite)
    : m_Sprite(parentSprite),
      m_ActiveAnimation(nullptr),
      m_LastAnimation(nullptr)
{
}
void Animator::SetCurrentAnimation(const std::string &name)
{
    if (m_Animations.find(name) != m_Animations.end())
        m_ActiveAnimation = &m_Animations[name];
    else
        m_ActiveAnimation = nullptr;
}
void Animator::AddAnimation(Animation &animation)
{
    m_Animations.insert(std::make_pair(animation.GetName(), animation));
}
void Animator::Update(const sf::Time &deltaTime)
{
    if (m_ActiveAnimation != nullptr)
    {
        if (m_ActiveAnimation != m_LastAnimation)
        {
            m_ActiveAnimation->Reset();
            m_ActiveAnimation->Play();
            m_LastAnimation = m_ActiveAnimation;
        }
        sf::IntRect rect = m_ActiveAnimation->Update(deltaTime);
        m_Sprite.setTextureRect(rect);
    }
}