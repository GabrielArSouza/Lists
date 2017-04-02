#include <iostream>
#include <cmath>
#include <algorithm>
 
struct Retangulo {
	int rw;
	int rh;
	int rx;
	int ry;
};


/*
	* @brief essa função verifica se há ou não interseão 
	* entre retangulos
*/

bool intersec (Retangulo R_a, Retangulo R_b, int extX_Ra,
			   int extY_Ra, int extX_Rb, int extY_Rb){

	//verificar se há interseção
	/*
		* @note essa condição não funciona quando
		* um retangulo está condito no outro.
	*/
	if (
		//verificar se a projeção do ponto ou do extremo
		//de um dos retangulos interseta a projeção
		//da largura do outro
		((R_a.rx >= R_b.rx and R_a.rx <= extX_Rb) or
		(extX_Ra >= R_b.rx)) and
		//verificar se a projeção do ponto ou do extremo
		//de um dos retangulos interseta a projeção
		//da altura do outro
		((R_a.ry >= R_b.ry and R_a.ry <= extY_Rb) or
		(extY_Ra >= R_b.ry))
		){

		std::cout << "Os retangulos se intersectam \n";
		return true;
	}else {
		return false;
	}

}

/*
	*@brief esta funcao calcula os dados
	* do retangulo formado pela interseçõa
	* de outros dois.
	*
	* @note a função assume que existe interseção.

*/

void RetInt (Retangulo R_a, Retangulo R_b, int extX_Ra,
			      int extY_Ra, int extX_Rb, int extY_Rb){

	//achar a largura e a altura
	int w = abs(std::min(R_a.rw, R_b.rw) - std::max(R_a.rx, R_b.rx));
	int h = abs(std::max(R_a.ry, R_b.ry) - std::min(R_a.rh, R_b.rh));

	//achar o ponto
	int px = std::max(R_a.rx, R_b.rx);
	int py = std::max (R_a.ry, R_b.ry);

	std::cout << "Dados do triangulo interseção";
	std::cout << "W: " << w << " H: " << h << " Px: "
	<< px << " Py: " << py << std::endl;	
		
}

int main (){
	Retangulo a;
	Retangulo b;
	Retangulo maior;
	Retangulo menor;
	
	int extX_maior;
	int extY_maior;
	int extX_menor;
	int extY_menor;

	std::cin >> a.rw >> a.rh >> a.rx >> a.ry;
	std::cin >> b.rw >> b.rh >> b.rx >> b.ry;

	//achar as extremidades de R_a
	int extX_Ra = a.rx + a.rw;
	int extY_Ra = a.ry + a.rh;
	//extremos de R_b
	int extX_Rb = b.rx + b.rw;
	int extY_Rb = b.ry + b.rh;

	if ((a.rw*a.rh) > (b.rw*b.rh)){
		maior.rw = a.rw;
		maior.rh = a.rh;
		maior.rx = a.rx;
		maior.ry = a.ry;
		menor.rw = b.rw;
		menor.rh = b.rh;
		menor.rx = b.rx;
		menor.ry = b.ry;

		extX_maior = extX_Ra;
		extY_maior = extY_Ra;
		extX_menor = extX_Rb;
		extY_menor = extY_Rb;

	}else {
		menor.rw = a.rw;
		menor.rh = a.rh;
		menor.rx = a.rx;
		menor.ry = a.ry;
		maior.rw = b.rw;
		maior.rh = b.rh;
		maior.rx = b.rx;
		maior.ry = b.ry;

		extX_maior = extX_Rb;
		extY_maior = extY_Rb;
		extX_menor = extX_Ra;
		extY_menor = extY_Ra;
	}
	

	if (intersec(a, b, extX_Ra, extY_Ra, extX_Rb, extY_Rb)){
		std::cout << "Os retangulos se intersetam\n";
		RetInt(a, b, extX_Ra, extY_Ra, extX_Rb, extY_Rb);
	//verificar o caso de um retangulo está contido em outro	
	}else if (
				(menor.rw <= maior.rw and menor.rh <= maior.rh) and
				(menor.rx >= maior.rx and menor.rx <= extX_maior) and
				(extX_menor >= maior.rx and extX_menor <= extX_maior) and
				(menor.ry >= maior.ry and menor.ry <= extY_maior) and
				(extY_menor >= maior.ry and extY_menor <= extY_maior)

			){

		std::cout << "Os retangulos se intersetam\n";
		std::cout << "as coordenadas do retangulo intersecao são\n";
		std::cout << "W: " << menor.rw << " H: " << menor.rh << " Px: " 
		<< menor.rx << " Py: " << menor.ry << std::endl;	
		
	}else {
		std::cout << "Os retangulos nao se intersetam\n";
	}

	return 0;
}