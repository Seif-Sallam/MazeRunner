#include "../headers/Animation.h"
#include <iostream>
Animation::Animation()
    : m_Name("UNSET"),
      m_FramePointer(0),
      m_Loop(false),
      m_Play(true),
      m_OverlappedTime(sf::Time::Zero)
{
}

Animation::Animation(const std::string &name)
    : m_Name(name),
      m_FramePointer(0),
      m_Loop(false),
      m_Play(true),
      m_OverlappedTime(sf::Time::Zero)
{
}

Animation::Animation(Animation &a)
    : m_Name(a.m_Name),
      m_FramePointer(a.m_FramePointer),
      m_Loop(a.m_Loop),
      m_Play(a.m_Play),
      m_OverlappedTime(a.m_OverlappedTime),
      m_Timer(a.m_Timer)
{
    for (auto &frame : a.m_Frames)
    {
        m_Frames.push_back(frame);
    }
}

Animation::Animation(const Animation &a)
    : m_Name(a.m_Name),
      m_FramePointer(a.m_FramePointer),
      m_Loop(a.m_Loop),
      m_Play(a.m_Play),
      m_OverlappedTime(a.m_OverlappedTime),
      m_Timer(a.m_Timer)
{
    for (auto &frame : a.m_Frames)
    {
        m_Frames.push_back(frame);
    }
}
void Animation::AddFrame(const sf::IntRect &rect, sf::Time delay)
{
    m_Frames.emplace_back(rect, delay);
}

void Animation::SetName(const std::string &name)
{
    m_Name = name;
}

void Animation::Play()
{
    m_Play = true;
}

void Animation::Stop()
{
    m_Play = false;
}

void Animation::Loop(bool value)
{
    m_Loop = value;
}

void Animation::Reset()
{
    m_FramePointer = 0;
}

sf::IntRect Animation::Update(const sf::Time &deltaTime)
{
    if (m_Play)
    {
        if (m_Frames.size() > 0)
        {
            m_OverlappedTime += m_Timer.getElapsedTime();
            while (m_OverlappedTime >= m_Frames[m_FramePointer % m_Frames.size()].delay)
            {
                m_OverlappedTime -= m_Frames[m_FramePointer % m_Frames.size()].delay;
                m_FramePointer++;
                if (m_FramePointer == m_Frames.size())
                {
                    if (!m_Loop)
                        Stop();
                }
            }
            return m_Frames[m_FramePointer & m_Frames.size()].bounds;
        }
        std::cout << "FRAMES\n";
    }
    return sf::IntRect(0, 0, 51, 44); // default size
}

std::string Animation::GetName()
{
    return m_Name;
}