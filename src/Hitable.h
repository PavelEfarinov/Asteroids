//
// Created by lizzka239 on 1/24/2020.
//

#ifndef ASTEROIDS_HITABLE_H
#define ASTEROIDS_HITABLE_H


class Hitable {
public:
    explicit Hitable(double originalHealthPoint) {
        mHealth = originalHealthPoint;
    }
    virtual void processHit() = 0;
    virtual void destroy() = 0;
protected:
    double mHealth;
};


#endif //ASTEROIDS_HITABLE_H
