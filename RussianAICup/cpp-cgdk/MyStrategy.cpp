#include "MyStrategy.h"

using namespace model;

MyStrategy::MyStrategy() { }

void MyStrategy::act(const Robot& me, const Rules& rules, const Game& game, Action& action) {

    ball.set(game.ball.x, game.ball.z, game.ball.y);
    ball_v.set(game.ball.velocity_x, game.ball.velocity_z, game.ball.velocity_y);

    if ( !me.touch ) {
        action.target_velocity_x = 0.0;
        action.target_velocity_z = 0.0;
        action.target_velocity_y = -MAX_ENTITY_SPEED;
        action.jump_speed        = 0.0;
        action.use_nitro         = true;
        return;
    }

    bool jump = (   ball.distTo(me.x, me.z, me.y) < (BALL_RADIUS + ROBOT_MAX_RADIUS)
                 && me.y < ball.y );

    for (const Robot &robot : game.robots) {
        if (   robot.is_teammate
            && robot.id != me.id) {
            if (robot.z < me.z) {
                is_attacker = true;
            }
        }
    }

    if (is_attacker) {
        for (int i = 0; i < 100; ++i) {
            double t = i * 0.1;
            Point3D ball_pos = ball + ball_v*t;
            if (   ball_pos.z > me.z
                && abs(ball.x) < (rules.arena.width / 2.0)
                && abs(ball.z) < (rules.arena.depth / 2.0) ) {
                Point2D delta_pos(ball_pos.x - me.x, ball_pos.z - me.z);
                double delta_pos_dist = delta_pos.dist();
                double need_speed = delta_pos_dist / t;
                if (0.5 * ROBOT_MAX_GROUND_SPEED < need_speed
                    && need_speed < ROBOT_MAX_GROUND_SPEED ) {
                    Point2D target_velocity(delta_pos.normalize(delta_pos_dist)*need_speed);
                    action.target_velocity_x = target_velocity.x;
                    action.target_velocity_z = target_velocity.z;
                    action.target_velocity_y = 0.0;
                    action.jump_speed = jump ? ROBOT_MAX_JUMP_SPEED : 0.0;
                    action.use_nitro = false;
                    return;
                }
            }
        }
    }
    Point2D target_pos(0.0, -(rules.arena.depth / 2.0) + rules.arena.bottom_radius);
    if (ball_v.z < -EPS) {
        double t = (target_pos.z - ball.z) / ball_v.z;
        double x = ball.x + ball_v.x * t;
        if (abs(x) < (rules.arena.goal_width / 2.0)) {
            target_pos.x = x;
        }
    }
    Point2D target_velocity(target_pos.x - me.x, target_pos.z - me.z);
    target_velocity *= ROBOT_MAX_GROUND_SPEED;
    action.target_velocity_x = target_velocity.x;
    action.target_velocity_z = target_velocity.z;
    action.target_velocity_y = 0.0;
    action.jump_speed = jump ? ROBOT_MAX_JUMP_SPEED : 0.0;
    action.use_nitro = false;
}