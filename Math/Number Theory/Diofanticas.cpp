/*
  - Ecuacion de la forma ax + by = c, donde a, b, c 
    son constantes y hay que encontrar x, y.
  - Cada valor debe ser entero.
  - Solo tiene solucion si c es divisible por gcd(a, b)
  - En este algoritmo se obtiene un par de soluciones x, y. Una
    vez se obtiene una solucion se pueden formar infinitar a partir
    de esta, asi: (x + (k*b)/gcd(a, b), y - (k*a)/gcd(a, b)), donde
    k es un entero.
*/
// Complejidad: O(log(n)), siendo n el minimo entre a y b
void extendedEuclid(ll a, ll b, ll &x, ll &y, ll &mcd){
	if(b == 0){
		x = 1;
		y = 0;
		mcd = a;
	}
	else{
		extendedEuclid(b, a % b, x, y, mcd);
		x = y;
		y = (mcd - a*x) / b;
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll a, b, x, y, mcd;
	a = 146;
	b = 388;
	extendedEuclid(a, b, x, y, mcd);
	cout<<mcd<<" "<<x<<" "<<y<<endl;
}