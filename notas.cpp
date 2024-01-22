#include<iostream>
using namespace std;

int ValidarNumEstudiantes()
{
	int ne;
	do
	{
		cout<<"Ingrese numero de estudiantes:   "<<endl;
		cin>>ne;
	}while(ne<=0);
	return ne;
}
float ValidarNota()
{
	float nota;
	do
	{
		cout<<"Ingrese nota (0-20)  :  "<<endl;
		cin>>nota;
	}while(nota<0 or nota>20);
	return nota;	
}
int ValidarEdad()
{
	int edad;
	do
	{
		cout<<endl;
		cout<<"Ingrese edad (0-120) :  "<<endl;
		cin>>edad;
	}while(edad<0 or edad>120);
	return edad;
}
char ValidarEC()
{
 	char Estadocivil;
 	do
	 {  cout<<"Ingrese Estado Civil :  "<<endl; 
	    cout<<"Opciones (c,s,v,d) "<<endl;
   		cin>>Estadocivil;
   		Estadocivil=toupper(Estadocivil);
	 }
   while(Estadocivil!='C' and Estadocivil!='S' and Estadocivil!='V' and Estadocivil!='D'); 
   return Estadocivil;
}
float CalcularPromedio(float sum)
{
	float prom;
	prom=sum/4;
	return prom;
}
float CalcularPromedioSalon(float sumsalon, int num)
{
	float proms;
	proms=sumsalon/num;
	return proms;
}
int CantAprobados(float prom, int caprob)
{
	if(prom>=10.5)
		caprob++;
	return caprob;		
}
int CantCasadosAprobados( float prom,char EC, int ccaprob)
{
	if(prom>=10.5 and EC == 'C')
		ccaprob++;
	return ccaprob;		
}
int CantDesaprobados(float prom, int cdes)
{
	if(prom<10.5)
		cdes++;
	return cdes;		
}
int CantMayoresEdadDesaprobados(float prom, int edad, int cmedes)
{
	if(prom<10.5 and edad>17)
		cmedes++;
	return cmedes;		
}

int CantCsdoMayorEdadAprobado(float prom, int edad, int CcmeAp,char EC)
{
	if(prom>10.5 and edad>17)
		if (EC == 'C')
				CcmeAp++;	
		
	return CcmeAp++;		
}

int CantMenorEdadAprobado(float prom, int edad, int cmeAp)
{
	if(prom>10.5 and edad<17)
		cmeAp++;
	return cmeAp;		
}


void Procesar()
{
	int num,i,j,caprob=0,cdes=0,ccaprob=0,cmedes=0,CcmeAp=0,cmeAp=0;
	float nota,sum=0,prom=0, edad, proms, sumsalon;
	char EC;
	num=20;
		/*   num=ValidarNumEstudiantes();*/
	for(i=0;i<num;i++)
	{
		cout<<endl;	
		cout<<"E S T U D I A N T E    N U M E R O  "<<i+1<<endl;	
		edad=ValidarEdad();
	    EC=ValidarEC();
		sum=0;
		for(j=0;j<4;j++)
		{
			nota=ValidarNota();
			sum=sum+nota;
			
		}	
		prom=CalcularPromedio(sum);
		cout<<"El Promedio del alumno es----------:"<<prom<<endl;
		sumsalon=sumsalon+prom; 
		proms=CalcularPromedioSalon(sumsalon,num);
	
		caprob=CantAprobados(prom,caprob);
		cdes=CantDesaprobados(prom,cdes);
		ccaprob=CantCasadosAprobados( prom,EC,ccaprob);
		cmedes=CantMayoresEdadDesaprobados(prom,edad,cmedes);
		CcmeAp=CantCsdoMayorEdadAprobado(prom,edad,CcmeAp,EC);
		cmeAp=CantMenorEdadAprobado(prom,edad,cmeAp);
	}
	cout<<endl;	
	cout<<"**R E S U M E N   D E   L O S   A L U M N O S**"<<endl;	
	cout<<endl;	
    cout<<"El Promedio del salon es________: "<<proms<<endl;
	cout<<"La cant de aprobados es_________: "<<caprob<<endl;
	cout<<"La cant de desaprobados es________: "<<cdes<<endl;
	/* cout<<"La cant de casados aprobados______: "<<ccaprob<<endl;*/
	/*cout<<"La cant de mayores de edad desaprobados es__: "<<cmedes<<endl;*/
	cout<<"La cant de mayores de edad Aprobados Casado es__: "<<CcmeAp<<endl;		
	cout<<"La cant de menores de edad Aprobados es__: "<<cmeAp<<endl;
	
}
int main()
{
	Procesar();
	return 0;
}
