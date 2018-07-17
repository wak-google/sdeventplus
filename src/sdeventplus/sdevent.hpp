#pragma once

#include <systemd/sd-event.h>

namespace sdeventplus
{

class SdEventInterface
{
  public:
    virtual ~SdEventInterface() = default;

    virtual int sd_event_default(sd_event **event) const = 0;
    virtual int sd_event_new(sd_event **event) const = 0;
    virtual sd_event *sd_event_ref(sd_event *event) const = 0;
    virtual sd_event *sd_event_unref(sd_event *event) const = 0;

    virtual int sd_event_loop(sd_event *event) const = 0;
};

class SdEventImpl : public SdEventInterface
{
  public:
    int sd_event_default(sd_event **event) const override
    {
        return ::sd_event_default(event);
    }

    int sd_event_new(sd_event **event) const override
    {
        return ::sd_event_default(event);
    }

    sd_event *sd_event_ref(sd_event *event) const override
    {
        return ::sd_event_ref(event);
    }

    sd_event *sd_event_unref(sd_event *event) const override
    {
        return ::sd_event_unref(event);
    }

    int sd_event_loop(sd_event *event) const override
    {
        return ::sd_event_loop(event);
    }
};

extern SdEventImpl sdevent_impl;

} // namespace sdeventplus
