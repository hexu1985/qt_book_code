#include "custom_slider_widget.h"
#include "custom_slider_widgetplugin.h"

#include <QtCore/QtPlugin>

custom_slider_widgetPlugin::custom_slider_widgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void custom_slider_widgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool custom_slider_widgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *custom_slider_widgetPlugin::createWidget(QWidget *parent)
{
    return new custom_slider_widget(parent);
}

QString custom_slider_widgetPlugin::name() const
{
    return QLatin1String("custom_slider_widget");
}

QString custom_slider_widgetPlugin::group() const
{
    return QLatin1String("Example Custom Widgets");
}

QIcon custom_slider_widgetPlugin::icon() const
{
    return QIcon();
}

QString custom_slider_widgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString custom_slider_widgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool custom_slider_widgetPlugin::isContainer() const
{
    return false;
}

QString custom_slider_widgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"custom_slider_widget\" name=\"custom_slider_widget\">\n</widget>\n");
}

QString custom_slider_widgetPlugin::includeFile() const
{
    return QLatin1String("custom_slider_widget.h");
}

Q_EXPORT_PLUGIN2(custom_slider_widgetplugin, custom_slider_widgetPlugin)
