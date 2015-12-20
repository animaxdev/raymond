#ifndef __RAY3_H
#define __RAY3_H

#include "vec3.h"

namespace raymond
{

template <class T>
class ray3
{
public:
    ray3(const vec3<T>& origin, const vec3<T>& direction)
    {
        setOrigin(origin);
        setDirection(direction);
    }
    
    const vec3<T>& getOrigin()
    {
        return m_origin;
    }

    const ray3<T>& setOrigin(const vec3<T>& origin)
    {
        m_origin = origin;
    }

    const vec3<T>& getDirection()
    {
        return m_direction;
    }

    const ray3<T>& setDirection(const vec3<T>& direction)
    {
        m_direction = direction;
        m_direction.normalise();
    }

    vec3<T> getPointAtDistance(T d)
    {
        return m_origin + (m_direction*d);
    }

private:
    vec3<T> m_direction;
    vec3<T> m_origin;
    //T m_near;
    //T m_far;
};

typedef ray3<float> ray3f;

}

#endif // !__RAY3_H

