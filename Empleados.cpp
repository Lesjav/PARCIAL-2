#include<iostream>

using namespace std;

int opc=0,totalEmpleados = 0;

void menu();
void Cls();

void ingresar_Empleado();
void consultar_Empleados();
void consultarCodigo();
int EditarEmpleados(int codigoEmpleado);
int dato_empleado(int codigoEmpleado);
int funcion_calcular_sueldo(float num1, float num2);


struct Empleado{
		
	int *codigo;	
	string *nombre;
	string *apellido;	
	string *Puesto;
	float *Sueldo_Base;
	float *Bonificacion;
	
};

Empleado empleado;

int main(){
	
	empleado.codigo = new int [totalEmpleados];
	empleado.nombre = new string [150];
	empleado.apellido = new string [150];
	empleado.Puesto = new string [150];
	empleado.Sueldo_Base = new float [totalEmpleados];
	empleado.Bonificacion = new float [totalEmpleados];
			
	menu();
	
	system("PAUSE");
	return 0;
}

void menu(){
	
	cout<<"<<------Bienvenido------>>"<<endl<<endl;
	cout<<"1. Agregar empleado"<<endl;
	cout<<"2. Editar empleado"<<endl;
	cout<<"3. Buscar empleado"<<endl;
	cout<<"4. Ver todos los empleados"<<endl;
	cout<<"5. Salir"<<endl<<endl;
	cout<<"Dijite su opcion: ";
	scanf("%i" , &opc); 
	Cls();
	
	switch(opc)
	{
		case 1: ingresar_Empleado() ;break;
 		case 2: EditarEmpleados(0) ;break;
 		case 3: consultarCodigo() ;break;
 		case 4: consultar_Empleados() ;break;
 		case 5: Cls(); menu(); break;  
		default:cout<<"Opcion no valida";  
	}
 
system("pause");
Cls();
menu();

}

void ingresar_Empleado(){
	
 	cout<<"Ingrese los datos del empleado"<<endl;
 	
	cout<<"Codigo del empleado: ";		
	cin>>empleado.codigo[totalEmpleados];
	
	cin.ignore();	
	cout<<"Nombres del empleado: ";
	getline(cin,empleado.nombre[totalEmpleados]);
		
	cout<<"Apellidos del empleado: ";		
	getline(cin,empleado.apellido[totalEmpleados]);	
	
	cout<<"Puesto: ";
	getline(cin,empleado.Puesto[totalEmpleados]);
		
	cout<<"Sueldo base: ";
	cin>>empleado.Sueldo_Base[totalEmpleados];
	
	cout<<"Bonificacion: ";
	cin>>empleado.Bonificacion[totalEmpleados];
			
	totalEmpleados++;

	system("pause");
	Cls();
	menu();	

}

void consultar_Empleados(){
	cout<<"\t------Personas Registradas------"<<endl<<endl;
	cout<<"Listado de empleados:"<<endl;
	if (totalEmpleados==0){		
	cout<<"No se encuentra ningun empleado ingresado"<<endl;
	}else{
		for (int i = 0; i < totalEmpleados; i++)
		{
		cout<<"------------------------------------------------"<<endl;
		cout<<"Codigo: "<<empleado.codigo[i]<<endl;		
		cout<<"Nombres: "<<empleado.nombre[i]<<endl;	
		cout<<"Apellidos: "<<empleado.apellido[i]<<endl;					
		cout<<"Puesto: "<<empleado.Puesto[i]<<endl;		
		cout<<"Sueldo base: "<<empleado.Sueldo_Base[i]<<endl;	
		cout<<"Bonificacion: "<<empleado.Bonificacion[i]<<endl;		
		cout<<"Sueldo Total: "<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i])<<endl;
		}
	}	
}
int dato_empleado(int codigoEmpleado){
	for (int i = 0; i < totalEmpleados; i++)
	{
		if(empleado.codigo[i]==codigoEmpleado){			
			cout<<"Codigo: "<<empleado.codigo[i]<<endl;		
			cout<<"Nombres: "<<empleado.nombre[i]<<endl;	
			cout<<"Apellidos: "<<empleado.apellido[i]<<endl;					
			cout<<"Puesto: "<<empleado.Puesto[i]<<endl;		
			cout<<"Sueldo base: "<<empleado.Sueldo_Base[i]<<endl;	
			cout<<"Bonificacion: "<<empleado.Bonificacion[i]<<endl;
			cout<<"Sueldo Total: "<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i])<<endl;	
		}			
	}	
}
void consultarCodigo(){
	int codigoEmpleado;
	cout<<"Datos del empleado: ";
	cin>>codigoEmpleado;
	cout<<"------------------------------------------------"<<endl;	
	dato_empleado(codigoEmpleado);
	cout<<"------------------------------------------------"<<endl;
}

int EditarEmpleados(int codigoEmpleado){
	int id_registro, opc=0;
	string nombre, apellidos, puesto;
	float sueldo, bonificacion;
	
	if(codigoEmpleado==0){
		cout<<"Ingrese el codigo del empleado a modificar: ";
		cin>>codigoEmpleado;
	}	
	
	cout<<"------------------------------------------------"<<endl;
		for (int i = 0; i < totalEmpleados; i++)
	{
		if(empleado.codigo[i]==codigoEmpleado){			
			cout<<"Codigo: "<<empleado.codigo[i]<<endl;		
			cout<<"Nombres: "<<empleado.nombre[i]<<endl;	
			cout<<"Apellidos: "<<empleado.apellido[i]<<endl;					
			cout<<"Puesto: "<<empleado.Puesto[i]<<endl;		
			cout<<"Sueldo base: "<<empleado.Sueldo_Base[i]<<endl;	
			cout<<"Bonificacion: "<<empleado.Bonificacion[i]<<endl;
			cout<<"Sueldo Total: "<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i])<<endl;
			id_registro=i;
		}			
	}
	cout<<"------------------------------------------------"<<endl<<endl;
	
	cout<<"1. Editar Nombres"<<endl;
	cout<<"2. Editar Apellidos"<<endl;
	cout<<"3. Editar Puesto"<<endl;
	cout<<"4. Editar Sueldo"<<endl;
	cout<<"5. Editar Bonificacion"<<endl;
	cout<<"6. Seleccionar otro registro"<<endl<<endl;
	cout<<"7. Salir"<<endl<<endl;
	
	cout<<"Dijite su opcion: ";
	scanf("%i" , &opc); 
	
	switch(opc)
	{
	case 1: 
	 
		cout<<"Nuevos nombres: ";
		cin>>nombre;
		empleado.nombre[id_registro]=nombre;
		Cls();	
		EditarEmpleados(codigoEmpleado);
		
	;break;
 	case 2:
 		
	 	cout<<"Nuevos apellidos: ";
		cin>>apellidos;
		empleado.apellido[id_registro]=apellidos;
		Cls();	
		EditarEmpleados(codigoEmpleado);
				  
	;break;
 	case 3:
 		
	 	cout<<"Nuevo puesto: ";
		cin>>puesto;
		empleado.Puesto[id_registro]=puesto;
		Cls();	
		EditarEmpleados(codigoEmpleado);
		
	;break;
 	case 4: 
	 	cout<<"Nuevo Sueldo: ";
		cin>>sueldo;
		empleado.Sueldo_Base[id_registro]=sueldo;
		Cls();	
		EditarEmpleados(codigoEmpleado);
	;break;
 	case 5:
	 	cout<<"Nueva bonificacion: ";
		cin>>bonificacion;
		empleado.Bonificacion[id_registro]=bonificacion;
		Cls();	
		EditarEmpleados(codigoEmpleado);
	;break;
	case 6:
		EditarEmpleados(0);
	;break;
	case 7:
		Cls();
		menu();	
	;break;
	default:cout<<"Opcion no valida";  
	}													
}

int funcion_calcular_sueldo(float num1, float num2){
	float suma=0;	
	suma = num1+num2;
	return suma;
}

void Cls(){
	system("cls");
	
}


