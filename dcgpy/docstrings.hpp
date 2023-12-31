#ifndef DCGPY_DOCSTRINGS_HPP
#define DCGPY_DOCSTRINGS_HPP

#include <string>

namespace dcgpy
{
// utilities
std::string disable_threading_doc();
std::string enable_threading_doc();
	
// kernel set
std::string kernel_init_doc(const std::string &);
std::string kernel_set_init_doc(const std::string &);
std::string kernel_set_push_back_str_doc();
std::string kernel_set_push_back_ker_doc(const std::string &);

// expression
std::string expression_init_doc(const std::string &);
std::string expression_set_doc();
std::string expression_set_f_gene_doc();
std::string expression_mutate_doc();
std::string expression_loss_doc();
std::string expression_set_phenotype_correction_doc();
std::string expression_unset_phenotype_correction_doc();


// expression_weighted
std::string expression_weighted_set_weight_doc();
std::string expression_weighted_set_weights_doc();
std::string expression_weighted_get_weight_doc();

// expression_ann
std::string expression_ann_set_weight_doc();
std::string expression_ann_get_weight_doc();
std::string expression_ann_randomise_weights_doc();
std::string expression_ann_set_bias_doc();
std::string expression_ann_set_biases_doc();
std::string expression_ann_get_bias_doc();
std::string expression_ann_randomise_biases_doc();
std::string expression_ann_set_output_f_doc();
std::string expression_ann_n_active_weights_doc();
std::string expression_ann_sgd_doc();

// UDPs
std::string symbolic_regression_doc();
std::string symbolic_regression_init_doc();
std::string symbolic_regression_predict_doc();

// UDAs
std::string generic_set_bfe_doc();
std::string generic_uda_get_seed_doc();
std::string es4cgp_doc();
std::string es4cgp_get_log_doc();
std::string moes4cgp_doc();
std::string moes4cgp_get_log_doc();
std::string gd4cgp_doc();
std::string gd4cgp_get_log_doc();
std::string mes4cgp_doc();
std::string mes4cgp_get_log_doc();
std::string momes4cgp_doc();
std::string momes4cgp_get_log_doc();

// The symbolic Regressio Gym problems
// Classic
std::string generate_koza_quintic_doc();
// From our paper
std::string generate_P1_doc();
std::string generate_P2_doc();
std::string generate_P3_doc();
std::string generate_P4_doc();
std::string generate_P5_doc();
std::string generate_P6_doc();
std::string generate_P7_doc();
// From Vladi paper
std::string generate_kotanchek_doc();
std::string generate_salutowicz_doc();
std::string generate_salutowicz2d_doc();
std::string generate_uball5d_doc();
std::string generate_ratpol3d_doc();
std::string generate_sinecosine_doc();
std::string generate_ripple_doc();
std::string generate_ratpol2d_doc();
// NIST data
std::string generate_chwirut1_doc();
std::string generate_chwirut2_doc();
std::string generate_daniel_wood_doc();
std::string generate_gauss1_doc();
std::string generate_kirby2_doc();
std::string generate_lanczos2_doc();
std::string generate_misra1b_doc();
// MISC data
std::string generate_luca1_doc();

} // namespace dcgpy

#endif
