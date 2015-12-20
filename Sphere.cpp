#include "Sphere.h"

namespace raymond
{

bool Sphere::intersect(const vec3f& ray_orig, const vec3f& ray_dir, float* pIntersect)
{
    float int0, int1;
    float radiusSquared = maths::square(m_Radius);

    vec3f origToCenter = m_Center - ray_orig;

    float distOrigDotCenter = origToCenter.dot(ray_dir);
    if (distOrigDotCenter < 0.0f)
        return false;

    float distSquared = origToCenter.dot(origToCenter) - maths::square(distOrigDotCenter);
    if (distSquared > radiusSquared) 
        return false;

    float distIntDotCenter = maths::squareroot(radiusSquared - distSquared);
    int0 = distOrigDotCenter - distIntDotCenter;
    int1 = distOrigDotCenter + distIntDotCenter;

    *pIntersect = (int0 < int1 && int0 > 0.0f) ? int0 : int1;

    return true;
}

Sphere& Sphere::setPosition(const vec3f& p)
{
    m_Center = p;
    return *this;
}

const vec3f & Sphere::getPosition()
{
    return m_Center;
}

Sphere & Sphere::setRadius(float r)
{
    m_Radius = r;
    return *this;
}

float Sphere::getRadius()
{
    return m_Radius;
}

}//raymond