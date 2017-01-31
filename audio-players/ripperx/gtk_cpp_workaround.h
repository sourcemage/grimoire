#ifndef gtk_cpp_workaround_h
#define gtk_cpp_workaround_h
#ifdef __cplusplus
//proto is wrong, override here for C++
namespace 
{
  
inline void gtk_table_attach (GtkTable *table,
		       GtkWidget *child,
		       guint left_attach,
		       guint right_attach,
		       guint top_attach,
		       guint bottom_attach,
		       //GtkAttachOptions xoptions,
		       //GtkAttachOptions yoptions,
		       guint xoptions, guint yoptions,
		       guint xpadding,
		       guint ypadding
		       ) 
{
  gtk_table_attach(table,
		   child,
		   left_attach,
		   right_attach,
		   top_attach,
		   bottom_attach,
		   (GtkAttachOptions)xoptions, 
		   (GtkAttachOptions)yoptions,
		   xpadding,
		   ypadding
		   );
  
    };


}

#endif
#endif
