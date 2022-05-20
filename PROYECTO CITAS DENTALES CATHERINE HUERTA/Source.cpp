#include <iostream>
#include <string.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

//Avance 2 de Proyecto. Anna Catherine Pérez Huerta. Matricula: 2007598. Programación Básica Grupo 004. 

void Agendar();
void mostrarcitas();
void archivo();
void modificar();
void eliminar();

int agendar, * hora, * preciounitario, * numcita, * cantidadtratamientos;
string* nombre, * descripcion, * tratamientos;
float* precio = 0, * subtotal = 0;
int opc;
float PrecioLimpieza = 589, PrecioBlanqueamiento = 4000, PrecioEmpaste = 989, PrecioCirugia = 90000;
int cantcitas = 0;

int main()
{
	do {
		cout << "Menu de opciones" << endl;
		cout << "................." << endl;
		cout << "(1). Agendar Cita" << endl;
		cout << "(2). Modificar Cita" << endl;
		cout << "(3). Eliminar Cita" << endl;
		cout << "(4). Lista de Citas Vigentes" << endl;
		cout << "(5). Limpiar Pantalla" << endl;
		cout << "(6). Generar Archivo" << endl;
		cout << "(7). Salir" << endl;
		cout << "- Que numero de opcion desea elegir?" << endl;
		cin >> opc;

		switch (opc)
		{
		case 1: //Agendar Cita
			Agendar();
			return main();
			break;

		case 2: //Modificar Cita
			modificar();
			return main();
			break;

		case 3: //Eliminar Cita
			eliminar();
			return main();
			break;

		case 4: //Lista de citas vigentes
			mostrarcitas();
			return main();
			break;

		case 5: //Limpiar pantalla
			system("cls");
			break;

		case 6: //Generar Archivo
			archivo();
			return main();
			break;

		case 7: //Salir
			return EXIT_SUCCESS;

		default:
			cout << "Elija una opcion correcta" << endl;
			system("pause");
		}

		cout << "Quieres regresar al menu?" << endl << "Presiona 1 para regresar, 2 para salir" << endl;
		cin >> opc;

	} while (opc == 1);

	return 0;
}

void Agendar()
{
	system("cls");

	cout << "\nEscriba el numero de citas que desea agendar." << endl;
	cin >> agendar;

	numcita = new int[agendar];
	nombre = new string[agendar];
	hora = new int[agendar];
	tratamientos = new string[agendar];
	descripcion = new string[agendar];
	preciounitario = new int[agendar];
	cantidadtratamientos = new int[agendar];
	subtotal = new float[agendar];
	precio = new float[agendar];

	for (int i = 0; i < agendar; i++)
	{
		cout << "Agendar Cita" << endl;
		while (getchar() != '\n');
		cout << "\nIntroduce tu nombre: ";
		getline(cin, nombre[i]);
		do {
			cout << "Introduce la hora del tratamiento: (formato 24 horas) : ";
			cin >> hora[i];
			if (hora[i] >= 25)
			{
				cout << "La hora no es valida." << endl;
			}
		} while (hora[i] >= 25);

		cout << "\n Tenemos la siguiente lista de tratamientos: " << endl;
		cout << "(1). Limpieza" << endl;
		cout << "(2). Blanqueamiento" << endl;
		cout << "(3). Empaste dental" << endl;
		cout << "(4). Cirugia maxilofacial" << endl;
		cout << "Que tratamiento desea adquirir? ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\nDescripcion: La limpieza dental se hace habitualmente con un aparato de ultrasonidos el cual tiene una punta fina que entra en vibracion cuando toca un objeto duro, en este caso el diente o el sarro. \n";
			tratamientos[i] = "\nLimpieza: La limpieza dental se hace habitualmente con un aparato de ultrasonidos el cual tiene una punta fina que entra en vibracion cuando toca un objeto duro, en este caso el diente o el sarro.  ";
			cout << "\n Este tratamiento tiene un costo de " << PrecioLimpieza << " pesos" << endl;;
			preciounitario[i] = PrecioLimpieza;
			cout << "\n Cuantos tratamientos desea adquirir? " << endl;
			cin >> cantidadtratamientos[i];
			subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
			precio[i] = subtotal[i] + (subtotal[i] * 0.16);
			cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
			cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
			system("pause");
			break;

		case 2:
			cout << "\n Descripcion: El blanqueamiento dental es un tratamiento de odontologia estetica que tiene por objetivo eliminar las manchas dentales y hacer que la denticion adquiera una tonalidad mas blanca y brillante. \n";
			tratamientos[i] = "\nBlanqueamiento dental: El blanqueamiento dental es un tratamiento de odontologia estetica que tiene por objetivo eliminar las manchas dentales y hacer que la denticion adquiera una tonalidad mas blanca y brillante. \n";
			cout << "\n Este tratamiento tiene un costo de " << PrecioBlanqueamiento << " pesos";
			preciounitario[i] = PrecioBlanqueamiento;
			cout << "\n Cuantos tratamientos desea adquirir? ";
			cin >> cantidadtratamientos[i];
			subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
			precio[i] = subtotal[i] + (subtotal[i] * 0.16);
			cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
			cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
			system("pause");
			break;

		case 3:
			cout << "\n Descripcion:  El empaste dental es un procedimiento odontologico que tiene como objetivo eliminar una caries del diente afectado.";
			tratamientos[i] = "\nEmpaste dental:  El empaste dental es un procedimiento odontologico que tiene como objetivo eliminar una caries del diente afectado.";
			cout << "\n Este tratamiento tiene un costo de " << PrecioEmpaste << " pesos";
			preciounitario[i] = PrecioEmpaste;
			cout << "\n Cuantos tratamientos desea adquirir? ";
			cin >> cantidadtratamientos[i];
			subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
			precio[i] = subtotal[i] + (subtotal[i] * 0.16);
			cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
			cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
			system("pause");
			break;

		case 4:
			cout << "\n Cirugia Maxilofacial: La cirugia maxilofacial es la especialidad medico-quirurgica que se centra en el estudio, diagnostico, tratamiento y rehabilitacion de las enfermedades congenitas o adquiridas de la cavidad oral, el esqueleto facial y las estructuras cervicales relacionadas. ";
			tratamientos[i] = "\n Cirugia Maxilofacial:  La cirugia maxilofacial es la especialidad medico-quirurgica que se centra en el estudio, diagnostico, tratamiento y rehabilitacion de las enfermedades congenitas o adquiridas de la cavidad oral, el esqueleto facial y las estructuras cervicales relacionadas. ";
			cout << "\n Este tratamiento tiene un costo de " << PrecioCirugia << " pesos";
			preciounitario[i] = PrecioCirugia;
			subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
			precio[i] = subtotal[i] + (subtotal[i] * 0.16);
			cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
			cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
			system("pause");
			break;

		default:
			cout << "Elija una opcion correcta" << endl;
			system("pause");
		}

	}
}

void mostrarcitas()
{
	for (int i = 0; i < agendar; i++)
	{
		cout << "\n....................." << endl;
		cout << "\nNombre del paciente: " << nombre[i] << endl;
		cout << "\nTratamiento elegido: " << tratamientos[i] << endl;
		cout << "\nHora de la la cita: " << hora[i] << endl;
		cout << "\nPrecio unitario: " << preciounitario[i] << endl;
		cout << "\nCantidad de tratamientos: " << cantidadtratamientos[i] << endl;
		cout << "\nTotal: " << precio[i] << endl;
		cout << "\n....................." << endl;
	}
}

void archivo()
{
	ofstream archivo;
	string nombrearchivo;
	string texto2;
	int texto;

	nombrearchivo = "Registro de Citas";
	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR, NO SE PUDO CREAR EL ARCHIVO" << endl;
		exit(1);
	}

	for (int i = 0; i < agendar; i++)
	{
		texto2 = nombre[i];
		archivo << "El nombre del paciente es: " << texto2 << "\t" << endl;
		texto2 = tratamientos[i];
		archivo << "El tratamiento a aplicar es: " << texto2 << "\t" << endl;
		texto = hora[i];
		archivo << "La hora de la cita es: " << texto << "\t" << endl;
		texto = preciounitario[i];
		archivo << "El precio unitario es: " << texto << "\t" << endl;
		texto = cantidadtratamientos[i];
		archivo << "La cantidad del tratamiento es: " << texto << "\t" << endl;
		texto = subtotal[i];
		archivo << "El subtotal es de: " << texto << "\t" << endl;
		texto = precio[i];
		archivo << "El total a pagar es de: " << texto << "\t" << endl;
	}
}

void modificar()
{
	int j, opc;
	cout << "Ingrese el numero de registro a modificar" << endl;
	cin >> j;
	j = j - 1;
	cout << "Ingrese el elemento que desea modificar" << endl << "1. Nombre del Paciente" << endl << "2. Hora de la cita" << endl << "3. Tratamiento" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese el nombre del paciente" << endl;
			getline(cin, nombre[i]);
		}
		break;

	case 2:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese el nuevo horario." << endl;
			cin >> hora[i];
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			cout << "\n Tenemos la siguiente lista de tratamientos: " << endl;
			cout << "(1). Limpieza" << endl;
			cout << "(2). Blanqueamiento" << endl;
			cout << "(3). Empaste dental" << endl;
			cout << "(4). Cirugia maxilofacial" << endl;
			cout << "Que tratamiento desea adquirir? ";
			cin >> opc;

			switch (opc)
			{
			case 1:
				cout << "\nDescripcion: La limpieza dental se hace habitualmente con un aparato de ultrasonidos el cual tiene una punta fina que entra en vibracion cuando toca un objeto duro, en este caso el diente o el sarro. \n";
				tratamientos[i] = "\nLimpieza: La limpieza dental se hace habitualmente con un aparato de ultrasonidos el cual tiene una punta fina que entra en vibracion cuando toca un objeto duro, en este caso el diente o el sarro.  ";
				cout << "\n Este tratamiento tiene un costo de " << PrecioLimpieza << " pesos" << endl;;
				preciounitario[i] = PrecioLimpieza;
				cout << "\n Cuantos tratamientos desea adquirir? " << endl;
				cin >> cantidadtratamientos[i];
				subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
				precio[i] = subtotal[i] + (subtotal[i] * 0.16);
				cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
				cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
				system("pause");
				break;

			case 2:
				cout << "\n Descripcion: El blanqueamiento dental es un tratamiento de odontologia estetica que tiene por objetivo eliminar las manchas dentales y hacer que la denticion adquiera una tonalidad mas blanca y brillante. \n";
				tratamientos[i] = "\nBlanqueamiento dental: El blanqueamiento dental es un tratamiento de odontologia estetica que tiene por objetivo eliminar las manchas dentales y hacer que la denticion adquiera una tonalidad mas blanca y brillante. \n";
				cout << "\n Este tratamiento tiene un costo de " << PrecioBlanqueamiento << " pesos";
				preciounitario[i] = PrecioBlanqueamiento;
				cout << "\n Cuantos tratamientos desea adquirir? ";
				cin >> cantidadtratamientos[i];
				subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
				precio[i] = subtotal[i] + (subtotal[i] * 0.16);
				cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
				cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
				system("pause");
				break;

			case 3:
				cout << "\n Descripcion:  El empaste dental es un procedimiento odontologico que tiene como objetivo eliminar una caries del diente afectado.";
				tratamientos[i] = "\nEmpaste dental:  El empaste dental es un procedimiento odontologico que tiene como objetivo eliminar una caries del diente afectado.";
				cout << "\n Este tratamiento tiene un costo de " << PrecioEmpaste << " pesos";
				preciounitario[i] = PrecioEmpaste;
				cout << "\n Cuantos tratamientos desea adquirir? ";
				cin >> cantidadtratamientos[i];
				subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
				precio[i] = subtotal[i] + (subtotal[i] * 0.16);
				cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
				cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
				system("pause");
				break;

			case 4:
				cout << "\n Cirugia Maxilofacial: La cirugia maxilofacial es la especialidad medico-quirurgica que se centra en el estudio, diagnostico, tratamiento y rehabilitacion de las enfermedades congenitas o adquiridas de la cavidad oral, el esqueleto facial y las estructuras cervicales relacionadas. ";
				tratamientos[i] = "\n Cirugia Maxilofacial:  La cirugia maxilofacial es la especialidad medico-quirurgica que se centra en el estudio, diagnostico, tratamiento y rehabilitacion de las enfermedades congenitas o adquiridas de la cavidad oral, el esqueleto facial y las estructuras cervicales relacionadas. ";
				cout << "\n Este tratamiento tiene un costo de " << PrecioCirugia << " pesos";
				preciounitario[i] = PrecioCirugia;
				subtotal[i] = preciounitario[i] * cantidadtratamientos[i];
				precio[i] = subtotal[i] + (subtotal[i] * 0.16);
				cout << "\n El costo total es de " << precio[i] << " pesos" << endl;
				cout << "\n El paciente " << nombre[i] << " tiene una cita programada a las " << hora[i] << " horas" << endl;
				system("pause");
				break;
			}
		}
		break;

	default:
		cout << "Elija una opcion correcta" << endl;
		system("pause");
	}
}


void eliminar()
{
	int j;
	cout << "Ingrese la cita a eliminar." << endl;
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		cout << "Eliminando registro..." << j + 1 << endl;
		nombre[i] = " ";
		hora[i] = 0;
		tratamientos[i] = " ";
		preciounitario[i] = 0;
		cantidadtratamientos[i] = 0;
		subtotal[i] = 0;
		precio[i] = 0;
	}
}