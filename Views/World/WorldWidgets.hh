#pragma once

#include <raindance/Core/HUD/Widgets/Widget.hh>

class EarthWidget : public IWidget
{
public:
	EarthWidget(IWidget* parent, glm::vec3 pos, glm::vec2 dimension)
	: IWidget("earth", parent, pos, dimension)
	{
		m_Icon = new Icon();
		m_Icon->load("globe", Resources_Earth_globe_png, sizeof(Resources_Earth_globe_png));
		m_State = true;
	}
	virtual ~EarthWidget()
	{
		delete m_Icon;
	}
	virtual void draw(Context* context, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
	{
		m_Icon->draw(context, projection * view * model, m_State ? glm::vec4(1.0, 1.0, 1.0, 1.0) : glm::vec4(0.5, 0.5, 0.5, 1.0), 0);
	}
	virtual void onMouseClick(MessageQueue& messages, int x, int y)
	{
		(void) x;
		(void) y;
		m_State = !m_State;
		messages.push(static_cast<IMessage*>(new WidgetMessage(m_State ? "show earth" : "hide earth")));
	}
private:
	bool m_State;
};

class WorldMapWidget : public IWidget
{
public:
	WorldMapWidget(IWidget* parent, glm::vec3 pos, glm::vec2 dimension)
	: IWidget("world map", parent, pos, dimension)
	{
		m_Icon = new Icon();
		m_Icon->load("worldmap", Resources_Earth_world_map_icon_png, sizeof(Resources_Earth_world_map_icon_png));
		m_State = true;
	}
	virtual ~WorldMapWidget()
	{
		delete m_Icon;
	}
	virtual void draw(Context* context, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
	{
		m_Icon->draw(context, projection * view * model, m_State ? glm::vec4(1.0, 1.0, 1.0, 1.0) : glm::vec4(0.5, 0.5, 0.5, 1.0), 0);
	}
	virtual void onMouseClick(MessageQueue& messages, int x, int y)
	{
		(void) x;
		(void) y;
		m_State = !m_State;
		messages.push(static_cast<IMessage*>(new WidgetMessage(m_State ? "show worldmap" : "hide worldmap")));
	}
private:
	bool m_State;
};
