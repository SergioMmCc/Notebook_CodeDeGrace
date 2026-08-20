// Tomado del template de Jiangly
using u128 = unsigned __int128;
using i128 = __int128;

// - Solo lo soportan algunos compiladores
// - Solo disponible en arquitecturas de 64 bits (como x86_64)
// - MSVC (Microsoft Visual C++) no lo soporta directamente
// - En CF se puede desde C++ 20 (la 17 es arquitectura de 32 bits)

// Convertir en cadena para imprimir
i128 x;
string s = "";
while(x > 0){
    s += '0' + (x % 10);
    x /= 10;
}
reverse(s.begin(), s.end());