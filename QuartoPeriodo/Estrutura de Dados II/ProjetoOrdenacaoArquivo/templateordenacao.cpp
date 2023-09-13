#include "templateordenacao.h"

TemplateOrdenacao::TemplateOrdenacao()
{

}

std::vector<Professor> TemplateOrdenacao::arraySelectionSort(){
    obj.buscarArquivos();
    array = obj.getArray();
    for(int step = 0; step <(int) array.size() -1; step++){
        int num_min = step;
        for(int i = step + 1; i < (int) array.size(); i++){
            if(!compararProfessor(array[i],array[num_min])){
                num_min = i;
            }
        }
        Professor temp = array[step];
        array[step] = array[num_min];
        array[num_min] = temp;
    }
//    for (int i = 0; i < (int)array.size(); i++) {
//        for (int j = i; j < (int)array.size() ; j++) {

//            if (!compararProfessor(array[i],array[j])) {
//                Professor temp = array[j];
//                array[j] = array[i];
//                array[i] = temp;
//            }
//        }
//    }
    return array;

}
