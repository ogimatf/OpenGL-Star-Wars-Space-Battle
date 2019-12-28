#ifndef _FUNCTION_H_
#define _FUNCTION_H_

/*crta neprijateljski laser*/
void draw_enemy_laser(int lane, double position);
/*crta prijateljski laser*/
void draw_ally_laser(int lane, double position);
/*crta eksploziju pri porazu*/
void draw_l_fireball(int lane, double size);
/*crta ekspolizje pri pobedi*/
void draw_w_fireball(double size);
/*crta health bar star-destroyer-a*/
void draw_health_bar(int hp);

#endif