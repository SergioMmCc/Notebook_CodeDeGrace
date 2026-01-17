// Operaciones de bits (x > 0)
// Cantidad de ceros a la derecha (lsb)
#define ictz(x) __builtin_ctz(x)
#define llctz(x) __builtin_ctzll(x)

// Cantidad de ceros a la izquierda
#define iclz(x) __builtin_clz(x) // (msb = 31 - __builtin_clz(x))
#define llclz(x) __builtin_clzll(x) // (msb = 63 - __builtin_clz(x))

// Cantidad de bits en 1
#define llpc(x) __builtin_popcountll(x)
#define ipc(x) __builtin_popcount(x)