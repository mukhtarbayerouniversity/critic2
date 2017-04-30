// Public interface for src/gui_interface.f90

//xx// Variables made available through host association in 
//xx// gui_interface.f90. See gui_interface.f90 for documentation.
// Atoms
struct c_atom {
  char name[11];
  int z;
  float r[3];
};
int nat;
struct c_atom *at;

// Bonds
struct c_bond {
  int i1;
  int i2;
  float r1[3];
  float r2[3];
  float rmid[3];
  float length;
  float rot[4][4];
};
int nbond;
struct c_bond *bond;

// Bounding box
float xmin[3];
float xmax[3];
float xcm[3];
float xmaxlen;

//xx// Procedures made available in gui_interface.f90

// Initialize critic2
extern "C" void critic2_initialize();

// End the critic2 run
extern "C" void critic2_end();

// Read a new molecule/crystal from an external file
extern "C" void call_structure(const char *filename, int size, int isMolecule); 

// Calculate critical points for the current field
extern "C" void call_auto(); 

extern "C" void get_num_atoms(int *n);
extern "C" void get_atom_position(int n, int *atomicN, double *x, double *y, double *z);
extern "C" void num_of_bonds(int n, int *nstarN);
extern "C" void get_atom_bond(int n_atom, int nstarIdx, int *connected_atom, bool *neighCrystal );
extern "C" void num_of_crit_points(int *n_critp);
extern "C" void get_cp_pos_type(int cpIdx, int *type, double *x, double *y, double *z); //get critical points from critic2 after thay have bean generated by auto_cp

