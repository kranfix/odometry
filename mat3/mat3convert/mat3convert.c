#ifndef github_com_kranfix_odometry_mat3_mat3convert_mat3convert_c
#define github_com_kranfix_odometry_mat3_mat3convert_mat3convert_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// TRANSFORMADE MATRIX
void kfxMat3_2Rpy(kfxMat3_t * m, kfxRpy_t * rpy){
  ////////// RPY //////////	
  rpy->p = -asin(m->r[2].e[0]);
		
  float cp = cos(rpy->p);
					
  rpy->r = asin(m->r[2].e[1]/cp);
  rpy->y = asin(m->r[1].e[0]/cp);
}

void kfxMat3_2Axisang(kfxMat3_t * m, kfxAxisang_t * axis){
  ////////// RPY //////////
  axis->a = acos(((m->r0.x + m->r1.y + m->r2.z) - 1)/2);

  float s = pow(2*sin(axis->a),-1);

  axis->x = s*(m->r[2].e[1] - m->r[1].e[2]);
  axis->y = s*(m->r[0].e[2] - m->r[2].e[0]);
  axis->z = s*(m->r[1].e[0] - m->r[0].e[1]);
}

void kfxMat3_2Quat(kfxMat3_t * m, kfxQuat_t * q){
  axis->a = acos(((m->r[0].e[0]+m->r[1].e[1]+m->r[2].e[2]) - 1)/2);

  float s = pow(2*sin(axis->a),-1);

  axis->x = s*(m->r[2].e[1] - m->r[1].e[2]);
  axis->y = s*(m->r[0].e[2] - m->r[2].e[0]);
  axis->z = s*(m->r[1].e[0] - m->r[0].e[1]);	

  ////////// QUATERNION //////////
  q->w = cos((axis->a)/2);
  q->x = sa * axis->x;
  q->y = sa * axis->y;
  q->z = sa * axis->z;
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_mat3_mat3convert_mat3convert_c
