using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace polynom
{
    class Polynomial
    {
        private int terms;
        private Term[] termArray;
        public int Terms
        {
            get
            {
                return terms;
            }
            set
            {
                terms = value;
            }
        }
        public Term[] TermArray
        {
            get
            {
                return termArray;
            }
            set
            {
                termArray = value;
            }
        }
        public Polynomial(int t)
        {
            terms = t;
            termArray = new Term[t];
            for (int i = 0; i < t; i++)
            {
                termArray[i] = new Term();
            }
        }
        public void set_term(int t, float c, int e)
        {
            termArray[t].Coef = c;
            termArray[t].Exp = e;
        }
        public void set_coef(int t, float c)
        {
            termArray[t].Coef = c;
        }
        public void set_exp(int t, int e)
        {
            termArray[t].Exp = e;
        }
        public float get_coef(int t)
        {
            return termArray[t].Coef;
        }
        public int get_exp(int t)
        {
            return termArray[t].Exp;
        }

        ////////////////////////////////////This Methode Add Two Polynomial //////////////////////////

        public static Polynomial operator +(Polynomial p1, Polynomial p2)
        {
            int counter = 0, p1term = 0, p2term = 0, rcounter = 0;

            ////////////////This Part Of Methode Calculate The Result TermArray Terms Number/////////////

            while (p1term < p1.terms && p2term < p2.terms)
            {

                if (p1.termArray[p1term].Exp == p2.termArray[p2term].Exp)
                {
                    float c = p1.termArray[p1term].Coef + p2.termArray[p2term].Coef;
                    if (c != 0)
                    {
                        counter++;
                        p1term++;
                        p2term++;
                    }
                    else
                    {
                        p1term++;
                        p2term++;
                    }
                }
                else if (p1.termArray[p1term].Exp < p2.termArray[p2term].Exp)
                {
                    counter++;
                    p2term++;
                }
                else
                {
                    counter++;
                    p1term++;
                }
            }
            while (p1term < p1.terms)
            {
                counter++;
                p1term++;
            }
            while (p2term < p2.terms)
            {
                counter++;
                p2term++;
            }

            //////////////////This Part Of Methode Get The Result And Set In The Result Polynomial Variable /////////
            Polynomial result = new Polynomial(counter);
            p1term = 0;
            p2term = 0;
            while (p1term < p1.terms && p2term < p2.terms)
            {
                if (p1.termArray[p1term].Exp == p2.termArray[p2term].Exp)
                {
                    float c = p1.termArray[p1term].Coef + p2.termArray[p2term].Coef;
                    if (c != 0)
                    {
                        result.termArray[rcounter] = new Term();
                        result.set_term(rcounter, c, p1.termArray[p1term].Exp);
                    }
                    rcounter++;
                    p1term++;
                    p2term++;
                }
                else if (p1.termArray[p1term].Exp < p2.termArray[p2term].Exp)
                {
                    result.termArray[rcounter] = new Term();
                    result.set_term(rcounter, p2.termArray[p2term].Coef, p2.termArray[p2term].Exp);
                    rcounter++;
                    p2term++;
                }
                else
                {
                    result.termArray[rcounter] = new Term();
                    result.set_term(rcounter, p1.termArray[p1term].Coef, p1.termArray[p1term].Exp);
                    rcounter++;
                    p1term++;
                }
            }
            while (p1term < p1.terms)
            {
                result.termArray[rcounter] = new Term();
                result.set_term(rcounter, p1.termArray[p1term].Coef, p1.termArray[p1term].Exp);
                rcounter++;
                p1term++;
            }
            while (p2term < p2.terms)
            {
                result.termArray[rcounter] = new Term();
                result.set_term(rcounter, p2.termArray[p2term].Coef, p2.termArray[p2term].Exp);
                rcounter++;
                p2term++;
            }
            return result;
        }
        ///////////////////   This Methide Multiply Two Polynomial //////////
        public static Polynomial operator *(Polynomial p1, Polynomial p2)
        {
            Polynomial result = new Polynomial(p1.terms);
            for (int i = 0; i < p1.terms; i++)
            {
                result.termArray[i] = new Term(0, 0);
            }
            //////////////////////////////// This Part Of Methode Multiply Term's Of First Polynomial ( p1 ) With All Term's Of (p2) And Set In The Result /////
            Polynomial temp = new Polynomial(p1.terms);
            for (int i = 0; i < p2.terms; i++)
            {
                for (int j = 0; j < p1.terms; j++)
                {
                    temp.termArray[j] = new Term();
                    temp.termArray[j].Exp = p2.termArray[i].Exp + p1.termArray[j].Exp;
                    temp.termArray[j].Coef = p2.termArray[i].Coef * p1.termArray[j].Coef; ;
                }
                result += temp;
            }
            return result;
        }
        public override string ToString()
        {
            string result = "";
            for (int i = 0; i < terms; i++)
            {
                if (termArray[i].Coef != 0)
                {
                    if (termArray[i].Exp == 1)
                        result += termArray[i].Coef + "x";
                    else if (termArray[i].Exp == 0)
                        result += termArray[i].Coef;
                    else
                        result += termArray[i].Coef + "x^" + termArray[i].Exp;
                    if (i < terms - 1 && termArray[i + 1].Coef != 0)
                        result += "+";
                }
            }
            return result;
        }
    }
}
