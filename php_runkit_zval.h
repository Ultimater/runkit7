#ifndef PHP_RUNKIT_ZVAL_H
#define PHP_RUNKIT_ZVAL_H

/* {{{ php_runkit_zval_resolve_class_constant */
static void php_runkit_zval_resolve_class_constant(zval **pp, zend_class_entry *ce TSRMLS_DC) {
	if (
	    Z_TYPE_PP(pp) == IS_CONSTANT_AST
#if RUNKIT_ABOVE53
	    || (Z_TYPE_PP(pp) & IS_CONSTANT_TYPE_MASK) == IS_CONSTANT
#endif
	) {
#if (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION >= 2) || (PHP_MAJOR_VERSION > 5)
		zval_update_constant_ex(pp, PHP_RUNKIT_CONSTANT_INDEX(1), ce TSRMLS_CC);
#else
		zval_update_constant(pp, ce TSRMLS_CC);
#endif
	}
}
/* }}} */

#endif