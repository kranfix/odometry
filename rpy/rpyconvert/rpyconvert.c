// TRANSFORMADE ROLL-PITCH-YAW
void kfxRpy_2Mat3(kfxRpy_t * rpy, kfxMat3_t * m){
	
	float cy = cos(rpy->y);
	float cp = cos(rpy->p);
	float cr = cos(rpy->r);
	float sy = sin(rpy->y);
	float sp = sin(rpy->p);
	float sr = sin(rpy->r);

	////////// MATRIX //////////

	m->r[0].e[0] = cy*cp;
	m->r[0].e[1] = cy*sp*sr - sy*cr;
	m->r[0].e[2] = cy*sp*cr + sy*sr;
	m->r[1].e[0] = sy*cp;
	m->r[1].e[1] = sy*sp*sr + cy*cr;
	m->r[1].e[2] = sy*sp*cr - cy*sr;
	m->r[2].e[0] = -sp;
	m->r[2].e[1] = cp*sr;
	m->r[2].e[2] = cp*cr;

}
void kfxRpy_2Quat(kfxRpy_t * rpy, kfxQuat_t * q){

	float cp = cos((rpy->p)/2);	
	float sp = sin((rpy->p)/2);
	
	////////// QUATERNION //////////
	q->w = cp*cos((rpy->y + rpy->r)/2);	
 	q->x = -sp*sin((rpy->y - rpy->r)/2);	
	q->y = sp*cos((rpy->y - rpy->r)/2);	
	q->z = cp*cos((rpy->y + rpy->r)/2);	

}
void kfxRpy_2Axisang(kfxRpy_t * rpy, kfxAxisang_t * axis){

	float cp = cos((rpy->p)/2);	
	float sp = sin((rpy->p)/2);

	////////// AXIS //////////	
	axis->a = 2*acos(cp*cos((rpy->y + rpy->r)/2));	
							
	float sa = pow(sen(axis->a/2),-1);		
							
	axis->x = -sa*sp*sin((rpy->y - rpy->r)/2);	
	axis->y = sa*sp*cos((rpy->y - rpy->r)/2);	
	axis->z = sa*cp*cos((rpy->y + rpy->r)/2);	

}
