//
// Created by lizzka239 on 1/24/2020.
//

#ifndef ASTEROIDS_HITABLE_H
#define ASTEROIDS_HITABLE_H


class Hitable {
public:
    explicit Hitable(double originalHealthPoint) {
        mHealthPoint = originalHealthPoint;
        mCurrentHealth = mHealthPoint;
    }
    virtual bool processHit(double harmPoint) = 0;
protected:
    double mHealthPoint;
    double mCurrentHealth;
};


#endif //ASTEROIDS_HITABLE_H
