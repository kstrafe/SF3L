////////////////////////////////////////////////////////////
//
// SF3L - Simple, Fast 3D Library
// Copyright © 2013 Kevin R. Stravers (macocio@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include "Light.hpp"


namespace sf3
{

    Light::Light()
    {
//         Could be placed in a separate part of the program.
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
//        glEnable(GL_COLOR_MATERIAL);
    }


    Light::~Light()
    {}


    void Light::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
//        glPushMatrix();
//        glLoadIdentity();

        float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
        float mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
        float mat_ambient_color[] = {0.8f, 0.8f, 0.2f, 1.0f};
        float mat_diffuse[] = {.1f, .5f, .8f, 1.0f};
        float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
        float no_shininess = 0.0f;
        float low_shininess = 5.0f;
        float high_shininess = 100.0f;
        float mat_emission[] = {0.3f, 0.2f, 0.2f, 0.0f};
        float mat_position[] = {m_position.x, m_position.y, m_position.z, 1.f};

        glColor4f(1.f, 1.f, 1.f);

//        glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 15.f);
        glLightfv(GL_LIGHT0, GL_AMBIENT, no_mat);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
        glLightfv(GL_LIGHT0, GL_POSITION, mat_position);

        glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
        glMaterialf(GL_FRONT, GL_SHININESS, no_shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

//        glPopMatrix();
    }



} // Namespace sf3
