#include <locale.h>
#include <stdio.h>
#include <string.h>

void nm(int valor, char *ext, int *sexo);
void ord(int valor, char *ext, int *sexo);
void numCalc(int tres, char *exte, int *sex);
void numCalcOrd(int tres, char *exte, int *sex);

int main() {
  setlocale(LC_ALL, "Portuguese");

  int inteiro, genero, tipo;
  char extenso[100];
  strcpy(extenso, "");

  printf("Digite um número inteiro entre 0 e 999.999.999: ");
  scanf("%i", &inteiro);
  printf("Selecione o gênero (1 = Masculino ou 2 = Feminino): ");
  getchar();
  scanf("%i", &genero);
  printf("Selecione o tipo (1 = cardinal ou 2 = ordinal): ");
  getchar();
  scanf("%i", &tipo);

  if (inteiro > 999999999 || inteiro < 0) {
    printf("Número inválido.");
  } else {
    if (tipo > 1) {
      ord(inteiro, extenso, genero);
      printf("\n%s\n", extenso);
    } else {
      nm(inteiro, extenso, genero);
      printf("\n%s\n", extenso);
    }
  }
}

void nm(int valor, char *ext, int *sexo) {
  int dm, m, c;
  char dmilhar[100], milhar[100], centena[100];

  strcpy(dmilhar, "");
  strcpy(milhar, "");
  strcpy(centena, "");

  dm = valor / 1000000;
  valor = valor % 1000000;
  m = valor / 1000;
  c = valor % 1000;

  numCalc(dm, dmilhar, sexo);
  strcat(ext, dmilhar);
  if (dm != 0) {
    if (dm != 1) {
      strcat(ext, " milhões, ");
    } else {
      strcat(ext, " milhão, ");
    }
  }
  numCalc(m, milhar, sexo);
  strcat(ext, milhar);
  if (m != 0) {
    strcat(ext, " mil, ");
  }
  numCalc(c, centena, sexo);
  strcat(ext, centena);
  strcat(ext, ".");
}
void ord(int valor, char *ext, int *sexo) {
  int dm, m, c;
  char dmilhar[100], milhar[100], centena[100];

  strcpy(dmilhar, "");
  strcpy(milhar, "");
  strcpy(centena, "");

  dm = valor / 1000000;
  valor = valor % 1000000;
  m = valor / 1000;
  c = valor % 1000;

  numCalc(dm, dmilhar, sexo);
  strcat(ext, dmilhar);
  if (dm != 0) {
    if (dm != 1) {
      strcat(ext, " milionésimo, ");
    } else {
      strcat(ext, " milionésimo, ");
    }
  }
  numCalc(m, milhar, sexo);
  strcat(ext, milhar);
  if (m != 0) {
    strcat(ext, " milésimo, ");
  }
  numCalcOrd(c, centena, sexo);
  strcat(ext, centena);
  strcat(ext, ".");
}
void numCalc(int tres, char *exte, int *sex) {
  int c, d, u, temp;
  char centena[100], dezena[100], unidade[100], numero[100];

  strcpy(numero, "");
  strcpy(centena, "");
  strcpy(dezena, "");
  strcpy(unidade, "");

  c = tres / 100;
  temp = tres % 100;
  d = temp / 10;
  u = temp % 10;

  switch (c) {
  case 1: {
    if (d == 0 && u == 0) {
      strcpy(centena, "cem");
    } else {
      strcpy(centena, "cento e ");
    }
  } break;
  case 2: {
    if (d == 0 && u == 0) {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "duzentos");
      } else {
        strcpy(centena, "duzentas");
      }
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "duzentos e ");
      } else {
        strcpy(centena, "duzentas e ");
      }
    }
  } break;
  case 3: {
    if (d == 0 && u == 0) {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "trezentos");
      } else {
        strcpy(centena, "trezentas");
      }
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "trezentos e ");
      } else {
        strcpy(centena, "trezentas e ");
      }
    }
  } break;
  case 4: {
    if (d == 0 && u == 0) {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "quatrocentos");
      } else {
        strcpy(centena, "quatrocentas");
      };
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "quatrocentos e ");
      } else {
        strcpy(centena, "quatrocentas e ");
      }
    }
  } break;
  case 5: {
    if (d == 0 && u == 0) {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "quinhentos");
      } else {
        strcpy(centena, "quinhentas");
      }
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "quinhentos e ");
      } else {
        strcpy(centena, "quinhentas e ");
      }
    }
  } break;
  case 6: {
    if (d == 0 && u == 0) {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "seiscentos");
      } else {
        strcpy(centena, "seiscentas");
      }
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "seiscentos e ");
      } else {
        strcpy(centena, "seiscentas e ");
      }
    }
  } break;
  case 7: {
    if (d == 0 && u == 0) {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "setecentos");
      } else {
        strcpy(centena, "setecentas");
      }
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "setecentos e ");
      } else {
        strcpy(centena, "setecentas e ");
      }
    }
  } break;
  case 8: {
    if (d == 0 && u == 0) {
      if (sex == 'M' || sex == 'm') {
        strcpy(centena, "oitocentos");
      } else {
        strcpy(centena, "oitocentas");
      }
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "oitocentos e ");
      } else {
        strcpy(centena, "oitocentas e ");
      }
    }
  } break;
  case 9: {
    if (d == 0 && u == 0) {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "novecentos");
      } else {
        strcpy(centena, "novecentas");
      }
    } else {
      if (sex == 1 || sex == 1) {
        strcpy(centena, "novecentos e ");
      } else {
        strcpy(centena, "novecentas e ");
      }
    }
  } break;
  case 0: {
  } break;
  }
  switch (d) {
  case 1: {
    switch (u) {
    case 0: {
      strcpy(dezena, "dez");
    } break;
    case 1: {
      strcpy(dezena, "onze");
    } break;
    case 2: {
      strcpy(dezena, "doze");
    } break;
    case 3: {
      strcpy(dezena, "treze");
    } break;
    case 4: {
      strcpy(dezena, "quatorze");
    } break;
    case 5: {
      strcpy(dezena, "quinze");
    } break;
    case 6: {
      strcpy(dezena, "dezesseis");
    } break;
    case 7: {
      strcpy(dezena, "dezessete");
    } break;
    case 8: {
      strcpy(dezena, "dezoito");
    } break;
    case 9: {
      strcpy(dezena, "dezenove");
    } break;
    }
  } break;
  case 2: {
    if (u == 0) {
      strcpy(dezena, "vinte");
    } else {
      strcpy(dezena, "vinte e ");
    }
  } break;
  case 3: {
    if (u == 0) {
      strcpy(dezena, "trinta");
    } else {
      strcpy(dezena, "trinta e ");
    }
  } break;
  case 4: {
    if (u == 0) {
      strcpy(dezena, "quarenta");
    } else {
      strcpy(dezena, "quarenta e ");
    }
  } break;
  case 5: {
    if (u == 0) {
      strcpy(dezena, "cinquenta");
    } else {
      strcpy(dezena, "cinquenta e ");
    }
  } break;
  case 6: {
    if (u == 0) {
      strcpy(dezena, "sessenta");
    } else {
      strcpy(dezena, "sessenta e ");
    }
  } break;
  case 7: {
    if (u == 0) {
      strcpy(dezena, "setenta");
    } else {
      strcpy(dezena, "setenta e ");
    }
  } break;
  case 8: {
    if (u == 0) {
      strcpy(dezena, "oitenta");
    } else {
      strcpy(dezena, "oitenta e ");
    }
  } break;
  case 9: {
    if (u == 0) {
      strcpy(dezena, "noventa");
    } else {
      strcpy(dezena, "noventa e ");
    }
  } break;
  case 0: {
  } break;
  }
  if (d != 1) {
    switch (u) {
    case 1: {
      if (sex == 1 || sex == 1) {
        strcpy(unidade, "um");
      } else {
        strcpy(unidade, "uma");
      }
    } break;
    case 2: {
      strcpy(unidade, "dois");
    } break;
    case 3: {
      strcpy(unidade, "três");
    } break;
    case 4: {
      strcpy(unidade, "quatro");
    } break;
    case 5: {
      strcpy(unidade, "cinco");
    } break;
    case 6: {
      strcpy(unidade, "seis");
    } break;
    case 7: {
      strcpy(unidade, "sete");
    } break;
    case 8: {
      strcpy(unidade, "oito");
    } break;
    case 9: {
      strcpy(unidade, "nove");
    } break;
    case 0: {
      strcpy(unidade, "");
    } break;
    }
  } else {
    switch (u) {
    case 0: {
      strcpy(unidade, "dez");
    } break;
    case 1: {
      strcpy(unidade, "onze");
    } break;
    case 2: {
      strcpy(unidade, "doze");
    } break;
    case 3: {
      strcpy(unidade, "treze");
    } break;
    case 4: {
      strcpy(unidade, "quatorze");
    } break;
    case 5: {
      strcpy(unidade, "quinze");
    } break;
    case 6: {
      strcpy(unidade, "dezesseis");
    } break;
    case 7: {
      strcpy(unidade, "dezessete");
    } break;
    case 8: {
      strcpy(unidade, "dezoito");
    } break;
    case 9: {
      strcpy(unidade, "dezenove");
    } break;
    }
  }

  strcpy(numero, centena);

  if (d == 1) {
    strcat(numero, dezena);
  } else {
    strcat(numero, dezena);
    strcat(numero, unidade);
  }
  strcat(exte, numero);
}
void numCalcOrd(int tres, char *exte, int *sex) {
  int c, d, u, temp;
  char centena[100], dezena[100], unidade[100], numero[100];

  strcpy(numero, "");
  strcpy(centena, "");
  strcpy(dezena, "");
  strcpy(unidade, "");

  c = tres / 100;
  temp = tres % 100;
  d = temp / 10;
  u = temp % 10;

  switch (c) {
  case 1: {
    strcpy(centena, "centésimo ");
  } break;
  case 2: {
    strcpy(centena, "ducentésimo ");
  } break;
  case 3: {
    strcpy(centena, "tricentésimo ");
  } break;
  case 4: {
    strcpy(centena, "quadrigentésimo ");
  } break;
  case 5: {
    strcpy(centena, "quingentésimo ");
  } break;
  case 6: {
    strcpy(centena, "seiscentésimo ");
  } break;
  case 7: {
    strcpy(centena, "septigentésimo ");
  } break;
  case 8: {
    strcpy(centena, "octigentésimo ");
  } break;
  case 9: {
    strcpy(centena, "nongentésimo ");
  } break;
  case 0: {
  } break;
  }
  switch (d) {
  case 1: {
    strcpy(dezena, "décimo");
  } break;
  case 2: {
    strcpy(dezena, "vigésimo ");
  } break;
  case 3: {
    strcpy(dezena, "trigésimo ");
  } break;
  case 4: {
    strcpy(dezena, "quadrigésimo ");
  } break;
  case 5: {
    strcpy(dezena, "quinquagésimo ");
  } break;
  case 6: {
    strcpy(dezena, "sexagésimo ");
  } break;
  case 7: {
    strcpy(dezena, "septuagésimo ");
  } break;
  case 8: {
    strcpy(dezena, "octogésimo ");
  } break;
  case 9: {
    strcpy(dezena, "nonagésimo ");
  } break;
  case 0: {
  } break;
  }
  switch (u) {
  case 1: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "primeiro");
    } else {
      strcpy(unidade, "primeira");
    }
  } break;
  case 2: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "segundo");
    } else {
      strcpy(unidade, "segunda");
    }
  } break;
  case 3: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "terceiro");
    } else {
      strcpy(unidade, "terceira");
    }
  } break;
  case 4: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "quarto");
    } else {
      strcpy(unidade, "quarta");
    }
  } break;
  case 5: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "quinto");
    } else {
      strcpy(unidade, "quinta");
    }
  } break;
  case 6: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "sexto");
    } else {
      strcpy(unidade, "sexta");
    }
  } break;
  case 7: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "sétimo");
    } else {
      strcpy(unidade, "sétima");
    }
  } break;
  case 8: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "oitavo");
    } else {
      strcpy(unidade, "oitava");
    }
  } break;
  case 9: {
    if (sex == 1 || sex == 1) {
      strcpy(unidade, "nono");
    } else {
      strcpy(unidade, "nona");
    }
  } break;
  case 0: {
    strcpy(unidade, "");
  } break;
  }

  strcpy(numero, centena);

  if (d == 1) {
    strcat(numero, dezena);
  } else {
    strcat(numero, dezena);
    strcat(numero, unidade);
  }
  strcat(exte, numero);
}