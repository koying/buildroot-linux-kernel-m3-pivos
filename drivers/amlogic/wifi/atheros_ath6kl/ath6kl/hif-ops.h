/*
 * Copyright (c) 2004-2011 Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef HIF_OPS_H
#define HIF_OPS_H

#include "hif.h"

static inline int hif_read_write_sync(struct ath6kl *ar, u32 addr, u8 *buf,
				      u32 len, u32 request)
{
	return ar->hif_ops->read_write_sync(ar, addr, buf, len, request);
}

static inline int hif_write_async(struct ath6kl *ar, u32 address, u8 *buffer,
				  u32 length, u32 request,
				  struct htc_packet *packet)
{
	return ar->hif_ops->write_async(ar, address, buffer, length,
					request, packet);
}
static inline void ath6kl_hif_irq_enable(struct ath6kl *ar)
{
	return ar->hif_ops->irq_enable(ar);
}

static inline void ath6kl_hif_irq_disable(struct ath6kl *ar)
{
	return ar->hif_ops->irq_disable(ar);
}

static inline struct hif_scatter_req *hif_scatter_req_get(struct ath6kl *ar)
{
	return ar->hif_ops->scatter_req_get(ar);
}

static inline void hif_scatter_req_add(struct ath6kl *ar,
				       struct hif_scatter_req *s_req)
{
	return ar->hif_ops->scatter_req_add(ar, s_req);
}

static inline int ath6kl_hif_enable_scatter(struct ath6kl *ar)
{
	return ar->hif_ops->enable_scatter(ar);
}

static inline int ath6kl_hif_scat_req_rw(struct ath6kl *ar,
					 struct hif_scatter_req *scat_req)
{
	return ar->hif_ops->scat_req_rw(ar, scat_req);
}

static inline void ath6kl_hif_cleanup_scatter(struct ath6kl *ar)
{
	return ar->hif_ops->cleanup_scatter(ar);
}

static inline int ath6kl_hif_suspend(struct ath6kl *ar)
{
	return ar->hif_ops->suspend(ar);
}

/*
 * Read from the ATH6KL through its diagnostic window. No cooperation from
 * the Target is required for this.
 */
static inline int ath6kl_diag_read32(struct ath6kl *ar, u32 address,
					u32 *data)
{
	return ar->hif_ops->diag_read32(ar, address, data);
}

/*
 * Write to the ATH6KL through its diagnostic window. No cooperation from
 * the Target is required for this.
 */
static inline int ath6kl_diag_write32(struct ath6kl *ar, u32 address,
					__le32 data)
{
	return ar->hif_ops->diag_write32(ar, address, data);
}

static inline int ath6kl_hif_bmi_recv_buf(struct ath6kl *ar,
					u8 *buf, u32 len, bool want_timeout)
{
	return ar->hif_ops->bmi_recv_buf(ar, buf, len, want_timeout);
}

static inline int ath6kl_hif_bmi_send_buf(struct ath6kl *ar, u8 *buf,
					u32 len)
{
	return ar->hif_ops->bmi_send_buf(ar, buf, len);
}

static inline int ath6kl_hif_get_stat(struct ath6kl *ar, u8 *buf,
					int buf_len)
{
	return ar->hif_ops->get_stat(ar, buf, buf_len);
}

static inline int ath6kl_hif_set_max_sche(struct ath6kl *ar, 
					u32 max_sche_tx, u32 max_sche_rx)
{
	return ar->hif_ops->set_max_sche(ar, max_sche_tx, max_sche_rx);
}
#endif
