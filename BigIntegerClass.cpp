#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
using namespace std;

string subtract(string s1,string s2);
string add(string s1,string s2);
string multiply(string s1,string s2);
string divide(string s1,string s2);
string removeTrailing(string s1);
string gcd(string s1,string s2);
int handleSign(string s1,string s2);

string removeTrailing(string s1);

string gcd(string s1,string s2)
{
	int length;
	int diff;
	int sign=0;
	length=s2.length()>=s1.length()?s2.length():s1.length();
    diff=s2.length()>s1.length()?s2.length()-s1.length():s1.length()-s2.length();

    if(s2.length()>s1.length())
    {

        for(int i=0;i<diff;i++)
        {
            s1.insert(0,"0");
        }

    }
    else
    {
        for(int i=0;i<diff;i++)
        {
            s2.insert(0,"0");
        }

    }

	switch(handleSign(s1,s2))
	{

		case 1:s1.erase(0,1);
				break;
		case 2:s2.erase(0,1);
				break;
		case 3: s1.erase(0,1);
				s1.erase(0,1);
				break;
	}

	if(s1=="0")
	{
		return s2;

	}
	if(s2=="0")
	{
		return s1;
	}
	while(s1!=s2)
	{

		if(s1>s2)
		s1=subtract(s1,s2);
		else
		s2=subtract(s2,s1);


	}


	return s1;





}





string removeTrailing(string large)
{

	 
        
        int first;
    
        if(large[0]=='0')
            first=0;
        if(large[0]=='-')
            first=1;
        int zero_count=0;
        int i=first;
        while(large[i]=='0')
        {
            zero_count+=1;
            i+=1;    
        }

    
        i=first;
        while(zero_count)
        {
            large.erase(i,1);
            zero_count-=1;
        }


    
	if(large.empty() || (large.length()==1 && large[0]=='-'))
		{
		large="0";
		}
	


	return large;



}













string divide(string s1,string s2)
{

	int length;
	int diff;
	int sign=0;
	if(s2=="0")
		return "error";
	if(s1=="0")
	{
		
		return "0";
	}

	length=s2.length()>=s1.length()?s2.length():s1.length();
    diff=s2.length()>s1.length()?s2.length()-s1.length():s1.length()-s2.length();

	if(s2.length()>s1.length())
    {

        for(int i=0;i<diff;i++)
        {
            s1.insert(0,"0");
        }

    }
    else
    {
        for(int i=0;i<diff;i++)
        {
            s2.insert(0,"0");
        }

    }








	switch(handleSign(s1,s2))
	{

		case 1:s1.erase(0,1);
				sign=1;
				break;
		case 2:s2.erase(0,1);
				sign=1;
				break;
		case 3: s1.erase(0,1);
				s1.erase(0,1);
				break;
	}

	
	



	if(strcmp(s1.c_str(),s2.c_str())<0)
	{
		return "0";


	}

	string dividend=s1;
	string divisor=s2;
	string  quotient="0";
	string remainder=dividend;
	
	while(remainder>=divisor){

		remainder=subtract(dividend,divisor);
		dividend=remainder;
		quotient=add(quotient,"1");

	}

	if(sign)
		quotient.insert(0,"-");

	return quotient;

}




int handleSign(string s1,string s2)
{

    if(s1[0]=='-' && s2[0]!='-')
    {
        return 1;
    }
    else if(s1[0]!='-' && s2[0]=='-')
    {
        return 2;
    }
    else if(s1[0]=='-' && s2[0]=='-')
        return 3;
    return 4;
}


string multiply(string s1,string s2)
{

	int sign=0;

	if(s1=="0" || s2=="0")
	{
		
		return "0";
	}


	

	switch(handleSign(s1,s2))
	{

		case 1:s1.erase(0,1);
				sign=1;
				break;
		case 2:s2.erase(0,1);
				sign=1;
				break;
		case 3: s1.erase(0,1);
				s1.erase(0,1);
				sign=0;
				break;
	}
	string large;
	string small;
	if(s1.length()<s2.length())
		{
			large=s2;
			small=s1;
		}
		else
		{
			large=s1;
			small=s2;
		}
	int temp1=0;
	int temp2=0;
	int carry=0;
	int shift=0;
	string value="0";
	string partial_sum;
	for(int i=small.length()-1;i>=0;i--)
	{
		
		int digit1=small[i]-'0';
		partial_sum.insert(0,shift,'0');		
		for(int j=large.length()-1;j>=0;j--)
		{
			int digit2=large[j]-'0';
			temp1=digit1*digit2;
			temp2=(temp1+carry)%10;
			carry=(temp1+carry)/10;
			partial_sum.insert(0,"0");
			partial_sum[0]=(char)(temp2+48);
			

		}
		
		if(carry>=1)
		{
			partial_sum.insert(0,"0");
			partial_sum[0]=(char)(carry+48);
		}
	//	cout<<partial_sum<<" "<<carry<<" "<<temp1<<" "<<temp2<<"\n";

	value=add(value,partial_sum);
	
	carry=0;
	shift+=1;
	partial_sum="";
	}
	

	if(sign)
		value.insert(0,"-");

	return value;



}



string add(string s1,string s2)
{
    int sign=0;
	string large=s2.length()>s1.length()?s2:s1;
    int length=s2.length()>s1.length()?s2.length():s1.length();
    int diff=s2.length()>s1.length()?s2.length()-s1.length():s1.length()-s2.length();
    if(s2.length()>s1.length())
    {

        for(int i=0;i<diff;i++)
        {
            s1.insert(0,"0");
        }

    }
    else
    {
        for(int i=0;i<diff;i++)
        {
            s2.insert(0,"0");
        }

    }


		if(handleSign(s1,s2)==3) //when both are negative
		{
			s1.erase(0,1);
			s2.erase(0,1);
			sign=1;
		}
		else if(handleSign(s1,s2)==1 || handleSign(s1,s2)==2) //any one negative call subtract
		{
			string s;
			if(handleSign(s1,s2)==1){
				s1.erase(0,1);
				if(s1<s2)
					s=subtract(s1,s2);
				else{
					s=subtract(s2,s1);
					sign=1;
				}
			}
			else if(handleSign(s1,s2)==2)
			{
				s2.erase(0,1);
				if(s1<s2){
					sign=1;
					s=subtract(s1,s2);
				}
				else
					s=subtract(s2,s1);

			}
			
			
				s=removeTrailing(s);
				return s; 
		}

	





    int partial_sum=0;
    int carry=0;
    for(int i=length-1;i>=0;i--)
    {



        partial_sum=(s2[i]-'0')+(s1[i]-'0')+carry;
	
        if(partial_sum>=10)
        {
            carry=1;
        }
        else
        {
            carry=0;
        }
    large[i]=(char)(partial_sum%10+48);

    partial_sum=0;

    }
    if(carry){

        large.insert(0,"0");
        large[0]=(char)(carry+48);
    }

     if(sign)
         large.insert(0,"-");


	sign=0;
	return large;


}

string subtract(string s1,string s2)
{
    int sign=0;
    int sign2=0;
   int sign1=0;
    int length;
    int diff=0;
	string large=s1;
    string small=s2;
	length=s2.length()>=s1.length()?s2.length():s1.length();
    diff=s2.length()>s1.length()?s2.length()-s1.length():s1.length()-s2.length();

   if(s2.length()>s1.length())
    {

        for(int i=0;i<diff;i++)
        {
            s1.insert(0,"0");
        }

    }
    else
    {
        for(int i=0;i<diff;i++)
        {
            s2.insert(0,"0");
        }

    }




		string s;
		switch(handleSign(s1,s2))
		{
			
			case 1:{  
					s1.erase(0,1);
					//s2.insert(0,"-");
					s=add(s1,s2);
					sign=1;
				
					break;
			}
			case 2:{s2.erase(0,1);
					
					s=add(s1,s2);
					sign=0;
				
					break;
			}
		if(sign)
			s.insert(0,"-");
		return s;

		}
		if(handleSign(s1,s2)==3){
				s2.erase(0,1);
				s1.erase(0,1);
				sign1=1;
			
		}


		
		if(s.length()>=1)
		{
			if(sign)
				s.insert(0,"-");
			return s;
		}


   
    
    

	if(strcmp(s1.c_str(),s2.c_str())<0)
	{
		large=s2;
		small=s1;
		if(sign1)
			sign=0;
		else
			sign=1;


	}
	if(strcmp(s1.c_str(),s2.c_str())>0)
	{
		large=s1;
		small=s2;
		if(sign2)
			sign=0;
		if(sign1)
			sign=1;
		
	}
	if(strcmp(s1.c_str(),s2.c_str())==0)
	{
		large=s1;
		small=s2;
		if(sign1)
			sign=1;
	}
   
    int borrow=0;
    int carry=0;
    int partial_diff=0;
    for(int i=length-1;i>=0;i--)
    {

        partial_diff=(large[i]-'0')-(small[i]-'0');
		
	
        if(partial_diff<0)
        {
            
            if(length>1){
                
            partial_diff=partial_diff+10-borrow;
            large[i]=(char)(partial_diff+48);

            }
            else
            {
                large[i]=(char)((partial_diff*-1)+48);

            }
            borrow=1;
        
        }
        else
        {


            if(borrow){
                if(partial_diff>0){
                    large[i]=char( ( (large[i]-'0')+47 )- (small[i]-'0'));
                    borrow=0;
                }
                else
                {
                    partial_diff=partial_diff+10-borrow;
                    large[i]=(char)(partial_diff+48);
                }
            }
            else
                large[i]=(char)(partial_diff+48);
            
        }

    partial_diff=0;

    }
    if(sign){

        large.insert(0,"-");
    }

  

    sign=sign1=sign2=0;
	return large;
}



int  main()
{


    int t;
    cin>>t;



    for(int i=1;i<=t;i++)
    {
        string s1;
    	cin>>s1;
    	string s2;
   	 	cin>>s2;
    	int k;
   		cin>>k;
			switch(k)
			{
				case 1: cout<<add(s1,s2)<<"\n";
						break;
				case 2:cout<<removeTrailing(subtract(s1,s2))<<"\n";
						break;
				case 3:cout<<multiply(s1,s2)<<"\n";
						break;
				case 4:cout<<divide(s1,s2)<<"\n";
				         break;
				 case 5:cout<<removeTrailing(gcd(s1,s2))<<"\n";
				         break;

			}

    }

    

return 1;



}
