#pragma once

#include "_cgo_export.h"


class WidgetWithEventHandler {
public:
  virtual void set_event_handler(int handlerId) = 0;
};
class WidgetWithResizeHandler {
public:
  virtual void set_resize_handler(uintptr_t handlerId) = 0;
};
template<class BaseWidget>
class EventHandler : public BaseWidget, public WidgetWithEventHandler, public WidgetWithResizeHandler {
public:
  template<class... Arg>
  EventHandler(Arg... args)
    : BaseWidget(args...) {}

  int handle(int event) final {
    if (m_eventHandlerId >= 0) {
      const int ret = _go_eventHandler(m_eventHandlerId, event);
      if (ret != 0) {
	return ret;
      }
    }
    return BaseWidget::handle(event);
  }

  void resize(int x, int y, int w, int h) final {
    BaseWidget::resize(x, y, w, h);
    if (m_resizeHandlerId != 0) {
      _go_callbackHandler(m_resizeHandlerId);
    }
  }


  void set_event_handler(int handlerId) final {
    m_eventHandlerId = handlerId;
  }

  void set_resize_handler(uintptr_t handlerId) final {
    m_resizeHandlerId = handlerId;
  }

protected:
  int m_eventHandlerId = -1;
  uintptr_t m_resizeHandlerId = 0;
};
