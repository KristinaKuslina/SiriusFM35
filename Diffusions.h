#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdexept>
#include <cmath>

namespace SiriusFM
{
  class DifusionGBM
  {
  private:
    double const m_mu;
    double const m_sigma;
  public:
    double mu(double S_t, double t) const
    {return m_mu * S_t;};
    double sigma(double S_t, double t) const
    {return m_sigma*S_t;};
    DiffusionGBM(double a_mu, double a_sigma): m_mu(a_mu), m_sigma(a_sigma)
    {if (m_sigma<=0)
      {
        printf('%s',"Invalid argument GBM");
        std:: invalid_argument("Invalid argument GBM")
      }
    }
}
;
  class DifusionCEV
  {
  private:
    double const m_mu;
    double const m_sigma;
    double const m_beta;
  public:
    double mu(double S_t)
    {return m_mu * S_t;};
		double sigma(double S_t)
    {return m_sigma * pow(S_t, m_beta);};
    DiffusionCEV(double a_mu, double a_sigma, double a_beta): m_mu(a_mu), m_sigma(a_sigma), m_beta(a_beta)
    {
      if(m_sigma <= 0 || m_beta <= 0)
				{
          printf('%s',"Invalid argument CEV");
          std:: invalid_argument("Invalid argument CEV")
				}
    }
  }
;
  class DifusionOU
  {
  private:
    double const m_theta;
		double const m_kappa;
		double const m_sigma;
  public:
    double mu(double S_t)
    {return m_kappa*(m_theta -  S_t);};
    double sigma(double S_t = 0)
    {return m_sigma;};
    DiffusionOU(double a_theta, double a_kappa, double a_sigma): m_theta(a_theta), m_kappa(a_kappa), m_sigma(a_sigma)
    {
      if(m_sigma <= 0)
        {
          printf('%s',"Invalid argument OU");
          std:: invalid_argument("Invalid argument OU")
        }
    }
  }
;
  class DifusionLipton
  {
  private:
    double const m_mu;
		double const m_sigma1;
		double const m_sigma2;
		double const m_sigma3;
  public:
    double mu(double S_t)
    {return m_mu * S_t;}
    double sigma(double S_t)
    {return m_sigma1 + m_sigma2 * S_t + m_sigma3 * S_t * S_t;}
    DiffusionLipton(double a_mu, double a_sigma1, double a_sigma2, double a_sigma3):
    m_mu(a_mu), m_sigma1(a_sigma1), m_sigma2(a_sigma2), m_sigma3(a_sigma3)
    {
      if(m_sigma2*m_sigma2 >= 4 * m_sigma1 * m_sigma3)
        {
          printf('%s',"Invalid argument Lipton");
          std:: invalid_argument("Invalid argument Lipton")
        }
    }
  }
  ;
  class DifusionCIR
  {
  private:
    double const m_theta;
    double const m_kappa;
    double const m_sigma;
    //Дописать??????????????????????????????
  }

}
