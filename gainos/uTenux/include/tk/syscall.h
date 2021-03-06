/*
 *----------------------------------------------------------------------
 *    micro T-Kernel
 *
 *    Copyright (C) 2006-2008 by Ken Sakamura. All rights reserved.
 *    micro T-Kernel is distributed under the micro T-License.
 *----------------------------------------------------------------------
 *
 *    Version:   1.01.00
 *    Released by T-Engine Forum(http://www.t-engine.org) at 2008/02/25.
 *
 *----------------------------------------------------------------------
 */

/*
 *	@(#)syscall.h
 *
 *	micro T-Kernel (Common parts)
 */

#ifndef __TK_SYSCALL_H__
#define __TK_SYSCALL_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Task creation */
#define TSK_SELF	0		/* Its own task specify */
#define TPRI_INI	0		/* Specify priority at task startup */
#define TPRI_RUN	0		/* Specify highest priority during
					   running */

#define TA_ASM		0x00000000UL	/* Program by assembler */
#define TA_HLNG		0x00000001UL	/* Program by high level programming
					   language */
#define TA_USERBUF	0x00000020UL	/* Specify user buffer */
#define TA_DSNAME	0x00000040UL	/* Use object name */

#define TA_RNG0		0x00000000UL	/* Execute by protection level 0 */
#define TA_RNG1		0x00000100UL	/* Execute by protection level 1 */
#define TA_RNG2		0x00000200UL	/* Execute by protection level 2 */
#define TA_RNG3		0x00000300UL	/* Execute by protection level 3 */

/* Task state tskstat */
#define TTS_RUN		0x00000001U	/* RUN */
#define TTS_RDY		0x00000002U	/* READY */
#define TTS_WAI		0x00000004U	/* WAIT */
#define TTS_SUS		0x00000008U	/* SUSPEND */
#define TTS_WAS		0x0000000cU	/* WAIT-SUSPEND */
#define TTS_DMT		0x00000010U	/* DORMANT */
#define TTS_NODISWAI	0x00000080U	/* Wait disable rejection state */

/* Wait factor tskwait */
#define TTW_SLP		0x00000001UL	/* Wait caused by wakeup wait */
#define TTW_DLY		0x00000002UL	/* Wait caused by task delay */
#define TTW_SEM		0x00000004UL	/* Semaphore wait */
#define TTW_FLG		0x00000008UL	/* Event flag wait */
#define TTW_MBX		0x00000040UL	/* Mail box wait */
#define TTW_MTX		0x00000080UL	/* Mutex wait */
#define TTW_SMBF	0x00000100UL	/* Message buffer send wait */
#define TTW_RMBF	0x00000200UL	/* Message buffer receive wait */
#define TTW_CAL		0x00000400UL	/* Rendezvous call wait */
#define TTW_ACP		0x00000800UL	/* Rendezvous accept wait */
#define TTW_RDV		0x00001000UL	/* Rendezvous end wait */
#define TTW_MPF		0x00002000UL	/* Fixed size memory pool wait */
#define TTW_MPL		0x00004000UL	/* Variable size memory pool wait */

/* Semaphore generation */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_FIRST	0x00000000UL	/* Give priority to task at head of
					   wait queue */
#define TA_CNT		0x00000002UL	/* Give priority to task whose
					   request counts is less */
#define TA_DSNAME	0x00000040UL	/* Use object name */

/* Mutex */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_INHERIT	0x00000002UL	/* Priority inherited protocol */
#define TA_CEILING	0x00000003UL	/* Upper limit priority protocol */
#define TA_DSNAME	0x00000040UL	/* Use object name */

/* Event flag */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_WSGL		0x00000000UL	/* Disable multiple tasks wait */
#define TA_WMUL		0x00000008UL	/* Enable multiple tasks wait */
#define TA_DSNAME	0x00000040UL	/* Use object name */

/* Event flag wait mode */
#define TWF_ANDW	0x00000000U	/* AND wait */
#define TWF_ORW		0x00000001U	/* OR wait */
#define TWF_CLR		0x00000010U	/* All clear specify */
#define TWF_BITCLR	0x00000020U	/* Only condition bit clear specify */

/* Mail box */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_MFIFO	0x00000000UL	/* Manage messages by FIFO */
#define TA_MPRI		0x00000002UL	/* Manage messages by priority
					   order */
#define TA_DSNAME	0x00000040UL	/* Use object name */

/* Message buffer */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_USERBUF	0x00000020UL	/* Specify user buffer */
#define TA_DSNAME	0x00000040UL	/* Use object name */

/* Rendezvous */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_DSNAME	0x00000040UL	/* Use object name */

/* Handler */
#define TA_ASM		0x00000000UL	/* Program by assembler */
#define TA_HLNG		0x00000001UL	/* Program by high level programming
					   language */

/* Variable size memory pool */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_USERBUF	0x00000020UL	/* Specify user buffer */
#define TA_DSNAME	0x00000040UL	/* Use object name */
#define TA_RNG0		0x00000000UL	/* Protection level 0 */
#define TA_RNG1		0x00000100UL	/* Protection level 1 */
#define TA_RNG2		0x00000200UL	/* Protection level 2 */
#define TA_RNG3		0x00000300UL	/* Protection level 3 */

/* Fixed size memory pool */
#define TA_TFIFO	0x00000000UL	/* Manage wait task by FIFO */
#define TA_TPRI		0x00000001UL	/* Manage wait task by priority
					   order */
#define TA_USERBUF	0x00000020UL	/* Specify user buffer */
#define TA_DSNAME	0x00000040UL	/* Use object name */
#define TA_RNG0		0x00000000UL	/* Protection level 0 */
#define TA_RNG1		0x00000100UL	/* Protection level 1 */
#define TA_RNG2		0x00000200UL	/* Protection level 2 */
#define TA_RNG3		0x00000300UL	/* Protection level 3 */

/* Cycle handler */
#define TA_ASM		0x00000000UL	/* Program by assembler */
#define TA_HLNG		0x00000001UL	/* Program by high level programming
					   language */
#define TA_STA		0x00000002UL	/* Cycle handler startup */
#define TA_PHS		0x00000004UL	/* Save cycle handler phase */
#define TA_DSNAME	0x00000040UL	/* Use object name */

#define TCYC_STP	0x00U		/* Cycle handler is not operating */
#define TCYC_STA	0x01U		/* Cycle handler is operating */

/* Alarm handler address */
#define TA_ASM		0x00000000UL	/* Program by assembler */
#define TA_HLNG		0x00000001UL	/* Program by high level programming
					   language */
#define TA_DSNAME	0x00000040UL	/* Use object name */

#define TALM_STP	0x00U		/* Alarm handler is not operating */
#define TALM_STA	0x01U		/* Alarm handler is operating */

/* System state */
#define TSS_TSK		0x00U	/* During execution of task part(context) */
#define TSS_DDSP	0x01U	/* During dispatch disable */
#define TSS_DINT	0x02U	/* During Interrupt disable */
#define TSS_INDP	0x04U	/* During execution of task independent part */
#define TSS_QTSK	0x08U	/* During execution of semi-task part */

#ifdef __cplusplus
}
#endif

/* System dependencies */
#include <tk/sysdepend/syscall_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Task creation information 		tk_cre_tsk
 */
typedef struct t_ctsk {
	VP	exinf;		/* Extended information */
	ATR	tskatr;		/* Task attribute */
	FP	task;		/* Task startup address */
	PRI	itskpri;	/* Priority at task startup */
	W	stksz;		/* User stack size (byte) */
	UB	dsname[8];	/* Object name */
	VP	bufptr;		/* User buffer */
#if TA_GP
	VP	gp;		/* Global pointer (gp) */
#endif
} T_CTSK;

/*
 * Task state information 		tk_ref_tsk
 */
typedef	struct t_rtsk {
	VP	exinf;		/* Extended information */
	PRI	tskpri;		/* Current priority */
	PRI	tskbpri;	/* Base priority */
	UINT	tskstat;	/* Task state */
	UW	tskwait;	/* Wait factor */
	ID	wid;		/* Wait object ID */
	INT	wupcnt;		/* Number of wakeup requests queuing */
	INT	suscnt;		/* Number of SUSPEND request nests */
} T_RTSK;

/*
 * Semaphore creation information		tk_cre_sem
 */
typedef	struct t_csem {
	VP	exinf;		/* Extended information */
	ATR	sematr;		/* Semaphore attribute */
	INT	isemcnt;	/* Semaphore initial count value */
	INT	maxsem;		/* Semaphore maximum count value */
	UB	dsname[8];	/* Object name */
} T_CSEM;

/*
 * Semaphore state information		tk_ref_sem
 */
typedef	struct t_rsem {
	VP	exinf;		/* Extended information */
	ID	wtsk;		/* Wait task ID */
	INT	semcnt;		/* Current semaphore value */
} T_RSEM;

/*
 * Mutex creation information		tk_cre_mtx
 */
typedef struct t_cmtx {
	VP	exinf;		/* Extended information */
	ATR	mtxatr;		/* Mutex attribute */
	PRI	ceilpri;	/* Upper limit priority of mutex */
	UB	dsname[8];	/* Object name */
} T_CMTX;

/*
 * Mutex state information		tk_ref_mtx
 */
typedef struct t_rmtx {
	VP	exinf;		/* Extended information */
	ID	htsk;		/* Locking task ID */
	ID	wtsk;		/* Lock wait task ID */
} T_RMTX;

/*
 * Event flag creation information	tk_cre_flg
 */
typedef	struct t_cflg {
	VP	exinf;		/* Extended information */
	ATR	flgatr;		/* Event flag attribute */
	UINT	iflgptn;	/* Event flag initial value */
	UB	dsname[8];	/* Object name */
} T_CFLG;

/*
 * Event flag state information		tk_ref_flg
 */
typedef	struct t_rflg {
	VP	exinf;		/* Extended information */
	ID	wtsk;		/* Wait task ID */
	UINT	flgptn;		/* Current event flag pattern */
} T_RFLG;

/*
 * Mail box creation information	tk_cre_mbx
 */
typedef	struct t_cmbx {
	VP	exinf;		/* Extended information */
	ATR	mbxatr;		/* Mail box attribute */
	UB	dsname[8];	/* Object name */
} T_CMBX;

/*
 * Mail box message header
 */
typedef struct t_msg {
	VP	msgque[1];	/* Area for message queue */
} T_MSG;

typedef struct t_msg_pri {
	T_MSG	msgque;		/* Area for message queue */
	PRI	msgpri;		/* Message priority */
} T_MSG_PRI;

/*
 * Mail box state information		tk_ref_mbx
 */
typedef	struct t_rmbx {
	VP	exinf;		/* Extended information */
	ID	wtsk;		/* Wait task ID */
	T_MSG	*pk_msg;	/* Next received message */
} T_RMBX;

/*
 * Message buffer creation information	tk_cre_mbf
 */
typedef	struct t_cmbf {
	VP	exinf;		/* Extended information */
	ATR	mbfatr;		/* Message buffer attribute */
	W	bufsz;		/* Message buffer size (byte) */
	INT	maxmsz;		/* Maximum length of message (byte) */
	UB	dsname[8];	/* Object name */
	VP	bufptr;		/* User buffer */
} T_CMBF;

/*
 * Message buffer state information 	tk_ref_mbf
 */
typedef struct t_rmbf {
	VP	exinf;		/* Extended information */
	ID	wtsk;		/* Receive wait task ID */
	ID	stsk;		/* Send wait task ID */
	INT	msgsz;		/* Next received message size (byte) */
	W	frbufsz;	/* Free buffer size (byte) */
	INT	maxmsz;		/* Maximum length of message (byte) */
} T_RMBF;

/*
 * Rendezvous port creation information	tk_cre_por
 */
typedef	struct t_cpor {
	VP	exinf;		/* Extended information */
	ATR	poratr;		/* Port attribute */
	INT	maxcmsz;	/* Maximum length of call message (byte) */
	INT	maxrmsz;	/* Maximum length of replay message (byte) */
	UB	dsname[8];	/* Object name */
} T_CPOR;

/*
 * Rendezvous port state information	tk_ref_por
 */
typedef struct t_rpor {
	VP	exinf;		/* Extended information */
	ID	wtsk;		/* Call wait task ID */
	ID	atsk;		/* Receive wait task ID */
	INT	maxcmsz;	/* Maximum length of call message (byte) */
	INT	maxrmsz;	/* Maximum length of replay message (byte) */
} T_RPOR;

/*
 * Interrupt handler definition information	tk_def_int
 */
typedef struct t_dint {
	ATR	intatr;		/* Interrupt handler attribute */
	FP	inthdr;		/* Interrupt handler address */
#if TA_GP
	VP	gp;		/* Global pointer (gp) */
#endif
} T_DINT;

/*
 * Variable size memory pool creation information	tk_cre_mpl
 */
typedef	struct t_cmpl {
	VP	exinf;		/* Extended information */
	ATR	mplatr;		/* Memory pool attribute */
	W	mplsz;		/* Size of whole memory pool (byte) */
	UB	dsname[8];	/* Object name */
	VP	bufptr;		/* User buffer */
} T_CMPL;

/*
 * Variable size memory pool state information	tk_ref_mpl
 */
typedef struct t_rmpl {
	VP	exinf;		/* Extended information */
	ID	wtsk;		/* Wait task ID */
	W	frsz;		/* Total size of free area (byte) */
	W	maxsz;		/* Size of maximum continuous free area
				   (byte) */
} T_RMPL;

/*
 * Fixed size memory pool state information	tk_cre_mpf
 */
typedef	struct t_cmpf {
	VP	exinf;		/* Extended information */
	ATR	mpfatr;		/* Memory pool attribute */
	W	mpfcnt;		/* Number of blocks in whole memory pool */
	W	blfsz;		/* Fixed size memory block size (byte) */
	UB	dsname[8];	/* Object name */
	VP	bufptr;		/* User buffer */
} T_CMPF;

/*
 * Fixed size memory pool state information	tk_ref_mpf
 */
typedef struct t_rmpf {
	VP	exinf;		/* Extended information */
	ID	wtsk;		/* Wait task ID */
	W	frbcnt;		/* Number of free area blocks */
} T_RMPF;

/*
 * Cycle handler creation information 	tk_cre_cyc
 */
typedef struct t_ccyc {
	VP	exinf;		/* Extended information */
	ATR	cycatr;		/* Cycle handler attribute */
	FP	cychdr;		/* Cycle handler address */
	RELTIM	cyctim;		/* Cycle interval */
	RELTIM	cycphs;		/* Cycle phase */
	UB	dsname[8];	/* Object name */
#if TA_GP
	VP	gp;		/* Global pointer (gp) */
#endif
} T_CCYC;

/*
 * Cycle handler state information	tk_ref_cyc
 */
typedef struct t_rcyc {
	VP	exinf;		/* Extended information */
	RELTIM	lfttim;		/* Remaining time until next handler startup */
	UINT	cycstat;	/* Cycle handler status */
} T_RCYC;

/*
 * Alarm handler creation information		tk_cre_alm
 */
typedef struct t_calm {
	VP	exinf;		/* Extended information */
	ATR	almatr;		/* Alarm handler attribute */
	FP	almhdr;		/* Alarm handler address */
	UB	dsname[8];	/* Object name */
#if TA_GP
	VP	gp;		/* Global pointer (gp) */
#endif
} T_CALM;

/*
 * Alarm handler state information	tk_ref_alm
 */
typedef struct t_ralm {
	VP	exinf;		/* Extended information */
	RELTIM	lfttim;		/* Remaining time until handler startup */
	UINT	almstat;	/* Alarm handler state */
} T_RALM;

/*
 * Version information		tk_ref_ver
 */
typedef struct t_rver {
	UH	maker;		/* OS manufacturer */
	UH	prid;		/* OS identification number */
	UH	spver;		/* Specification version */
	UH	prver;		/* OS product version */
	UH	prno[4];	/* Product number, Product management
				   information */
} T_RVER;

/*
 * System state information		tk_ref_sys
 */
typedef struct t_rsys {
	UINT	sysstat;	/* System state */
	ID	runtskid;	/* ID of task in execution state */
	ID	schedtskid;	/* ID of the task that should be the
				   execution state */
} T_RSYS;


/* ------------------------------------------------------------------------ */
/*
 * Definition for interface library automatic generation (mktksvc)
 */
/*** DEFINE_TKSVC ***/

/* [BEGIN SYSCALLS] */
IMPORT ID tk_cre_tsk( T_CTSK *pk_ctsk );
IMPORT ER tk_del_tsk( ID tskid );
IMPORT ER tk_sta_tsk( ID tskid, INT stacd );
IMPORT void tk_ext_tsk( void );
IMPORT void tk_exd_tsk( void );
IMPORT ER tk_ter_tsk( ID tskid );
IMPORT ER tk_dis_dsp( void );
IMPORT ER tk_ena_dsp( void );
IMPORT ER tk_chg_pri( ID tskid, PRI tskpri );
IMPORT ER tk_rot_rdq( PRI tskpri );
IMPORT ER tk_rel_wai( ID tskid );
IMPORT ID tk_get_tid( void );
IMPORT ER tk_get_reg( ID tskid, T_REGS *pk_regs, T_EIT *pk_eit, T_CREGS *pk_cregs );
IMPORT ER tk_set_reg( ID tskid, T_REGS *pk_regs, T_EIT *pk_eit, T_CREGS *pk_cregs );
IMPORT ER tk_ref_tsk( ID tskid, T_RTSK *pk_rtsk );
IMPORT ER tk_sus_tsk( ID tskid );
IMPORT ER tk_rsm_tsk( ID tskid );
IMPORT ER tk_frsm_tsk( ID tskid );
IMPORT ER tk_slp_tsk( TMO tmout );
IMPORT ER tk_wup_tsk( ID tskid );
IMPORT INT tk_can_wup( ID tskid );
IMPORT ID tk_cre_sem( T_CSEM *pk_csem );
IMPORT ER tk_del_sem( ID semid );
IMPORT ER tk_sig_sem( ID semid, INT cnt );
IMPORT ER tk_wai_sem( ID semid, INT cnt, TMO tmout );
IMPORT ER tk_ref_sem( ID semid, T_RSEM *pk_rsem );
IMPORT ID tk_cre_mtx( T_CMTX *pk_cmtx );
IMPORT ER tk_del_mtx( ID mtxid );
IMPORT ER tk_loc_mtx( ID mtxid, TMO tmout );
IMPORT ER tk_unl_mtx( ID mtxid );
IMPORT ER tk_ref_mtx( ID mtxid, T_RMTX *pk_rmtx );
IMPORT ID tk_cre_flg( T_CFLG *pk_cflg );
IMPORT ER tk_del_flg( ID flgid );
IMPORT ER tk_set_flg( ID flgid, UINT setptn );
IMPORT ER tk_clr_flg( ID flgid, UINT clrptn );
IMPORT ER tk_wai_flg( ID flgid, UINT waiptn, UINT wfmode, UINT *p_flgptn, TMO tmout );
IMPORT ER tk_ref_flg( ID flgid, T_RFLG *pk_rflg );
IMPORT ID tk_cre_mbx( T_CMBX* pk_cmbx );
IMPORT ER tk_del_mbx( ID mbxid );
IMPORT ER tk_snd_mbx( ID mbxid, T_MSG *pk_msg );
IMPORT ER tk_rcv_mbx( ID mbxid, T_MSG **ppk_msg, TMO tmout );
IMPORT ER tk_ref_mbx( ID mbxid, T_RMBX *pk_rmbx );
IMPORT ID tk_cre_mbf( T_CMBF *pk_cmbf );
IMPORT ER tk_del_mbf( ID mbfid );
IMPORT ER tk_snd_mbf( ID mbfid, VP msg, INT msgsz, TMO tmout );
IMPORT INT tk_rcv_mbf( ID mbfid, VP msg, TMO tmout );
IMPORT ER tk_ref_mbf( ID mbfid, T_RMBF *pk_rmbf );
IMPORT ID tk_cre_por( T_CPOR *pk_cpor );
IMPORT ER tk_del_por( ID porid );
IMPORT INT tk_cal_por( ID porid, UINT calptn, VP msg, INT cmsgsz, TMO tmout );
IMPORT INT tk_acp_por( ID porid, UINT acpptn, RNO *p_rdvno, VP msg, TMO tmout );
IMPORT ER tk_fwd_por( ID porid, UINT calptn, RNO rdvno, VP msg, INT cmsgsz );
IMPORT ER tk_rpl_rdv( RNO rdvno, VP msg, INT rmsgsz );
IMPORT ER tk_ref_por( ID porid, T_RPOR *pk_rpor );
IMPORT ER tk_def_int( UINT dintno, T_DINT *pk_dint );
IMPORT void tk_ret_int( void );
IMPORT ID tk_cre_mpl( T_CMPL *pk_cmpl );
IMPORT ER tk_del_mpl( ID mplid );
IMPORT ER tk_get_mpl( ID mplid, W blksz, VP *p_blk, TMO tmout );
IMPORT ER tk_rel_mpl( ID mplid, VP blk );
IMPORT ER tk_ref_mpl( ID mplid, T_RMPL *pk_rmpl );
IMPORT ID tk_cre_mpf( T_CMPF *pk_cmpf );
IMPORT ER tk_del_mpf( ID mpfid );
IMPORT ER tk_get_mpf( ID mpfid, VP *p_blf, TMO tmout );
IMPORT ER tk_rel_mpf( ID mpfid, VP blf );
IMPORT ER tk_ref_mpf( ID mpfid, T_RMPF *pk_rmpf );
IMPORT ER tk_set_tim( SYSTIM *pk_tim );
IMPORT ER tk_get_tim( SYSTIM *pk_tim );
IMPORT ER tk_get_otm( SYSTIM *pk_tim );
IMPORT ER tk_dly_tsk( RELTIM dlytim );
IMPORT ID tk_cre_cyc( T_CCYC *pk_ccyc );
IMPORT ER tk_del_cyc( ID cycid );
IMPORT ER tk_sta_cyc( ID cycid );
IMPORT ER tk_stp_cyc( ID cycid );
IMPORT ER tk_ref_cyc( ID cycid, T_RCYC *pk_rcyc );
IMPORT ID tk_cre_alm( T_CALM *pk_calm );
IMPORT ER tk_del_alm( ID almid );
IMPORT ER tk_sta_alm( ID almid, RELTIM almtim );
IMPORT ER tk_stp_alm( ID almid );
IMPORT ER tk_ref_alm( ID almid, T_RALM *pk_ralm );
IMPORT ER tk_ref_ver( T_RVER *pk_rver );
IMPORT ER tk_ref_sys( T_RSYS *pk_rsys );
/* [END SYSCALLS] */

#ifdef __cplusplus
}
#endif

#endif /* __TK_SYSCALL_H__ */
