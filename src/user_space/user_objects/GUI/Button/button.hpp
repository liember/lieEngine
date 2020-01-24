#pragma once

class button : public gameobj
{
private:
    const bool positionary;

    positionProperty *pos;
    textProperty *text;
    clickAreaProperty *area;

public:
    bool isClecked();
    bool isHovered();

    void setSize(int x, int y);
    void setPaddings(int x, int y);
    void setPos(int x, int y);

    void setBorederColor(int r, int g, int b);
    void setBgColor(int r, int g, int b);
    void setClickColor(int r, int g, int b);
    void setHoverColor(int r, int g, int b);
    void setTextColor(int r, int g, int b);

    void setDelay(double d);

    void press();

    button(int x, int y, const char *text);
    ~button();
};